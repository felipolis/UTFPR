defmodule Movies do
  require Logger
  require HTTPoison
  require Floki


  # ------------------- AdoroCinema -------------------
  def get_movies_adorocinema(key) do

    Enum.flat_map(1..10, fn page -> # Faz uma requisição para cada página

      url = if page == 1 do
        "https://www.adorocinema.com/filmes/melhores/"
      else
        "https://www.adorocinema.com/filmes/melhores/?page=#{page}"
      end

      Logger.info("Scraping page #{page} from #{url}")

      case HTTPoison.get(url) do
        {:ok, %HTTPoison.Response{status_code: 200, body: body}} -> # Se a requisição for bem sucedida
          content = body
            |> Floki.find("a.meta-title-link")
            |> Floki.attribute("href")

          Enum.map(content, fn link -> # Para cada link encontrado
            case HTTPoison.get("https://www.adorocinema.com" <> link) do
              {:ok, %HTTPoison.Response{status_code: 200, body: body}} -> # Se a requisição for bem sucedida
                fullLink = "https://www.adorocinema.com" <> link

                title = body
                  |> Floki.find("div.titlebar-title.titlebar-title-lg")
                  |> Floki.text()

                Logger.info("Scraped movie #{title}")

                sinopse = body
                  |> Floki.find("#synopsis-details")
                  |> Floki.find("div.content-txt")
                  |> Floki.text()

                # Logger.info("Scraped sinopse #{sinopse}")

                # Verifica se a key está presente no título (lowwercase) ou na sinopse (lowercase)
                if String.contains?(String.downcase(title), String.downcase(key)) || String.contains?(String.downcase(sinopse), String.downcase(key)) do
                  File.write("./output/#{key}-adorocinema.txt", title <> "\n" <> sinopse  <> "\n" <> fullLink <> "\n\n", [:append])

                  [{title, sinopse, fullLink}]
                else
                  # Se não estiver, retorna uma lista vazia
                  []
                end

              {:error, %HTTPoison.Error{reason: reason}} -> # Se a requisição falhar
                Logger.error("Failed to scrape movie #{link} with reason #{reason}")
                []
            end
          end)

        _ ->
          []
      end
    end)
  end

  # ------------------- Filmow -------------------
  def get_movies_filmow(key) do

    Enum.flat_map(1..6, fn page ->

      url = if page == 1 do
        "https://filmow.com/filmes-todos/?order=best&filters=&apply="
      else
        "https://filmow.com/filmes-todos/?order=best&filters=&apply=&pagina=#{page}"
      end

      Logger.info("Scraping page #{page} from #{url}")

      case HTTPoison.get(url) do
        {:ok, %HTTPoison.Response{status_code: 200, body: body}} -> # Se a requisição for bem sucedida
            content = body
              |> Floki.find("li.movie_list_item")
              |> Floki.find("span.wrapper")
              |> Floki.find("a.cover")
              |> Floki.attribute("href")
              |> Enum.uniq()

            Enum.map(content, fn link -> # Para cada link encontrado
              case HTTPoison.get("https://filmow.com" <> link) do
                {:ok, %HTTPoison.Response{status_code: 200, body: body}} ->
                  fullLink = "https://filmow.com" <> link

                  title = body
                    |> Floki.find("div.movie-title")
                    |> Floki.find("h1")
                    |> Floki.text()

                  Logger.info("Scraped movie #{title}")

                  sinopse = body
                    |> Floki.find("div.description")
                    |> Floki.find("p")
                    |> Floki.text()

                  # Logger.info("Scraped sinopse #{sinopse}")

                  # Verifica se a key está presente no título (lowwercase) ou na sinopse (lowercase)
                  if String.contains?(String.downcase(title), String.downcase(key)) || String.contains?(String.downcase(sinopse), String.downcase(key)) do
                    File.write("./output/#{key}-filmow.txt", title <> "\n" <> sinopse  <> "\n" <> fullLink <> "\n\n", [:append])

                    [{title, sinopse, fullLink}]
                  else
                    # Se não estiver, retorna uma lista vazia
                    []
                  end

                {:error, %HTTPoison.Error{reason: reason}} -> # Se a requisição falhar
                  Logger.error("Failed to scrape movie #{link} with reason #{reason}")
                  []
              end
            end)
      end
    end)
  end

  # ------------------- IMDB -------------------
  def get_movies_imdb(key) do

    url = "https://www.imdb.com/chart/top/?ref_=nv_mv_250"

    Logger.info("Scraping page from #{url}")

    case HTTPoison.get(url) do
      {:ok, %HTTPoison.Response{status_code: 200, body: body}} -> # Se a requisição for bem sucedida

          content = body
            |> Floki.find(".lister-list")
            |> Floki.find("tr")
            |> Floki.find("td.titleColumn")
            |> Floki.find("a")
            |> Floki.attribute("href")

          Enum.map(content, fn link -> # Para cada link encontrado
            case HTTPoison.get("https://www.imdb.com" <> link) do
              {:ok, %HTTPoison.Response{status_code: 200, body: body}} -> # Se a requisição for bem sucedida
                fullLink = "https://www.imdb.com" <> link

                title = body
                  |> Floki.find("div.kNzJA-D")
                  |> Floki.find("h1")
                  |> Floki.text()

                Logger.info("Scraped movie #{title}")

                sinopse = body
                  |> Floki.find("span.kcphyk")
                  |> Floki.text()

                # Logger.info("Scraped sinopse #{sinopse}")

                # Verifica se a key está presente no título (lowwercase) ou na sinopse (lowercase)
                if String.contains?(String.downcase(title), String.downcase(key)) || String.contains?(String.downcase(sinopse), String.downcase(key)) do
                  File.write("./output/#{key}-imdb.txt", title <> "\n" <> sinopse  <> "\n" <> fullLink <> "\n\n", [:append])

                  [{title, sinopse, fullLink}]
                else
                  # Se não estiver, retorna uma lista vazia
                  []
                end

              {:error, %HTTPoison.Error{reason: reason}} -> # Se a requisição falhar
                Logger.error("Failed to scrape movie #{link} with reason #{reason}")
                []
            end
          end)
    end
  end



  # ------------------- MAIN -------------------
  def main(key) do

    # Verifica se o diretorio output existe, se não existir, cria
    if !File.dir?("output") do
      File.mkdir("output")
    end

    Logger.info("Starting scraping for #{key}")

    movies = get_movies_adorocinema(key) ++ get_movies_filmow(key) ++ get_movies_imdb(key)

    Logger.info("Finished scraping for #{key}")

    movies
  end

end

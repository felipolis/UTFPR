defmodule Movies do
  require Logger
  require HTTPoison
  require Floki

  # ------------------- AdoroCinema -------------------
  def get_movies_adorocinema(key) do
    get_movies_adorocinema(key, 1, [])
  end

  defp get_movies_adorocinema(key, page, acc) do
    url = if page == 1 do
      "https://www.adorocinema.com/filmes/melhores/"
    else
      "https://www.adorocinema.com/filmes/melhores/?page=#{page}"
    end

    Logger.info("Scraping page #{page} from #{url}")

    case HTTPoison.get(url) do
      {:ok, %HTTPoison.Response{status_code: 200, body: body}} ->
        content = body
          |> Floki.find("a.meta-title-link")
          |> Floki.attribute("href")

        movies = Enum.map(content, fn link ->
          case HTTPoison.get("https://www.adorocinema.com" <> link) do
            {:ok, %HTTPoison.Response{status_code: 200, body: movie_body}} ->
              fullLink = "https://www.adorocinema.com" <> link

              title = movie_body
                |> Floki.find("div.titlebar-title.titlebar-title-lg")
                |> Floki.text()

              Logger.info("Scraped movie #{title}")

              sinopse = movie_body
                |> Floki.find("#synopsis-details")
                |> Floki.find("div.content-txt")
                |> Floki.text()

              if String.contains?(String.downcase(title), String.downcase(key)) ||
                 String.contains?(String.downcase(sinopse), String.downcase(key)) do
                File.write("./output/#{key}-adorocinema.txt", title <> "\n" <> sinopse <> "\n" <> fullLink <> "\n\n", [:append])

                [{title, sinopse, fullLink}]
              else
                []
              end

            {:error, %HTTPoison.Error{reason: reason}} ->
              Logger.error("Failed to scrape movie #{link} with reason #{reason}")
              []
          end
        end)

        case movies do
          [] ->
            acc
          _ ->
            get_movies_adorocinema(key, page + 1, acc ++ movies)
        end

      _ ->
        acc
    end
  end

  # ------------------- Filmow -------------------
  def get_movies_filmow(key) do
    get_movies_filmow(key, 1, [])
  end

  defp get_movies_filmow(key, page, acc) do
    url = if page == 1 do
      "https://filmow.com/filmes-todos/?order=best&filters=&apply="
    else
      "https://filmow.com/filmes-todos/?order=best&filters=&apply=&pagina=#{page}"
    end

    Logger.info("Scraping page #{page} from #{url}")

    case HTTPoison.get(url) do
      {:ok, %HTTPoison.Response{status_code: 200, body: body}} ->
        content = body
          |> Floki.find("li.movie_list_item")
          |> Floki.find("span.wrapper")
          |> Floki.find("a.cover")
          |> Floki.attribute("href")
          |> Enum.uniq()

        movies = Enum.map(content, fn link ->
          case HTTPoison.get("https://filmow.com" <> link) do
            {:ok, %HTTPoison.Response{status_code: 200, body: movie_body}} ->
              fullLink = "https://filmow.com" <> link

              title = movie_body
                |> Floki.find("div.movie-title")
                |> Floki.find("h1")
                |> Floki.text()

              Logger.info("Scraped movie #{title}")

              sinopse = movie_body
                |> Floki.find("div.description")
                |> Floki.find("p")
                |> Floki.text()

              if String.contains?(String.downcase(title), String.downcase(key)) ||
                 String.contains?(String.downcase(sinopse), String.downcase(key)) do
                File.write("./output/#{key}-filmow.txt", title <> "\n" <> sinopse <> "\n" <> fullLink <> "\n\n", [:append])

                [{title, sinopse, fullLink}]
              else
                []
              end

            {:error, %HTTPoison.Error{reason: reason}} ->
              Logger.error("Failed to scrape movie #{link} with reason #{reason}")
              []
          end
        end)

        case movies do
          [] ->
            acc
          _ ->
            get_movies_filmow(key, page + 1, acc ++ movies)
        end

      _ ->
        acc
    end
  end

  # ------------------- IMDB -------------------
  def get_movies_imdb(key) do
    url = "https://www.imdb.com/chart/top/?ref_=nv_mv_250"

    Logger.info("Scraping page from #{url}")

    case HTTPoison.get(url) do
      {:ok, %HTTPoison.Response{status_code: 200, body: body}} ->
        content = body
          |> Floki.find(".lister-list")
          |> Floki.find("tr")
          |> Floki.find("td.titleColumn")
          |> Floki.find("a")
          |> Floki.attribute("href")

        Enum.map(content, fn link ->
          case HTTPoison.get("https://www.imdb.com" <> link) do
            {:ok, %HTTPoison.Response{status_code: 200, body: movie_body}} ->
              fullLink = "https://www.imdb.com" <> link

              title = movie_body
                |> Floki.find("div.kNzJA-D")
                |> Floki.find("h1")
                |> Floki.text()

              Logger.info("Scraped movie #{title}")

              sinopse = movie_body
                |> Floki.find("p[data-testid=plot]")
                |> Floki.find("span[data-testid=plot-xl]")
                |> Floki.text()

              if String.contains?(String.downcase(title), String.downcase(key)) ||
                 String.contains?(String.downcase(sinopse), String.downcase(key)) do
                File.write("./output/#{key}-imdb.txt", title <> "\n" <> sinopse <> "\n" <> fullLink <> "\n\n", [:append])

                [{title, sinopse, fullLink}]
              else
                []
              end

            {:error, %HTTPoison.Error{reason: reason}} ->
              Logger.error("Failed to scrape movie #{link} with reason #{reason}")
              []
          end
        end)

      _ ->
        []
    end
  end

  # ------------------- MAIN -------------------
  def main(key) do
    if !File.dir?("output") do
      File.mkdir("output")
    end

    Logger.info("Starting scraping for #{key}")

    adorocinema_task = Task.async(fn -> get_movies_adorocinema(key) end)
    filmow_task = Task.async(fn -> get_movies_filmow(key) end)
    imdb_task = Task.async(fn -> get_movies_imdb(key) end)

    adorocinema_movies = Task.await(adorocinema_task, :infinity)
    filmow_movies = Task.await(filmow_task, :infinity)
    imdb_movies = Task.await(imdb_task, :infinity)

    movies = adorocinema_movies ++ filmow_movies ++ imdb_movies

    Logger.info("Finished scraping for #{key}")

    movies
  end
end

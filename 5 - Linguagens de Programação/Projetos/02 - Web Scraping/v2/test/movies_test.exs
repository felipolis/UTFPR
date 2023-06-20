defmodule MoviesTest do
  use ExUnit.Case
  doctest Movies

  test "search_movies" do
    key = "action"
    result = Movies.main(key)
    assert length(result) > 0
  end
end

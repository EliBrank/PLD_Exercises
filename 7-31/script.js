const apiKey = '277d9a366e11543e1f7521576e9b14c8';
const genres = `https://api.themoviedb.org/3/genre/movie/list?language=en&api_key=${apiKey}`;
const imgBaseUrl = 'http://image.tmdb.org/t/p/w342';

function search () {
  const genreId = $('#genres').val();
  const genreSearch = `https://api.themoviedb.org/3/discover/movie?with_genres=${genreId}&api_key=${apiKey}`;
  $.getJSON(genreSearch, function (data) {
    $.each(data.results, function (i, film) {
      const imgUrl = imgBaseUrl + film.poster_path;
      let template = `
        <div class='movie'>
          <img class='lightbulb-effect' src='${imgUrl}'>
          <div class='film-info'>
            <h2>${film.original_title}</h2>
            <p class='description'>${film.overview}</p>
          </div>
        </div>
`;
      $('#content').append(template);
    });
  });
}

$(document).ready(function () {
  $.getJSON(genres, function (data) {
    $.each(data.genres, function (i, genres) {
      let opt = document.createElement('option');
      opt.value = genres.id;
      opt.innerText = genres.name;
      $('select').append(opt);
    });
  });
  $('button').on('click', search);
});

const apiKey = "6d29bbab";

document.getElementById("form-submit").addEventListener("submit", getIp);
let page = 1;
let searchWord = document.getElementById("searchWord");
function getIp(e) {
  e.preventDefault();
  let iVal = searchWord.value;
  search(iVal, page);
}

const renderMovieNotFound = (error = "Movie not found!") => {
  const movieNotFoundContainer = document.createElement("div");
  movieNotFoundContainer.innerHTML = confirm(error);
};

function search(ip, page) {
  let url = `https://www.omdbapi.com/?s=${ip}&page=${page}&apikey=${apiKey}`;

  fetch(url)
    .then((res) => res.json())
    .then((data) => {
      if (data.Response === "False") {
        renderMovieNotFound(data.Error);
      } else {
        let output = "";
        data.Search.forEach((result) => {
          let poster = result.Poster ? result.Poster : "";
          output += `<div class="col-md-3">
          <div class="card">
            <img class="card-img-top" src="${poster}" alt="Poster">
            <div class="card-body">
              <h6 class="card-title">${result.Title} ${result.Year}</h6>
              <a class="btn btn-primary" id="${result.imdbID}">Show more</a>
            </div>
          </div>
           </div>`;
        });
        output += `
      <div class="container mt-5 moviesInfo">
        <div class="row">
      <nav aria-label="Page navigation example">
      <ul class="pagination">
        <li class="page-item" id="previous"><a class="page-link" onclick="previous()">Previous</a></li>
        <li class="page-item" id="next"><a class="page-link" onclick="next()">Next</a></li>
      </ul>
      </nav>
      </div>
      </div>
          `;
        document.getElementById("results").innerHTML = output;
      }
    });
}

function next() {
  document.getElementById("results").innerHTML = "";
  let iVal = searchWord.value;
  page++;
  search(iVal, page);
}

function previous() {
  let iVal = searchWord.value;
  if (page != 1) {
    document.getElementById("results").innerHTML = "";
    page--;
    search(iVal, page);
  } else {
    page = 1;
  }
}

const btnShowMore = document.getElementById("btn-show-more");
const moviesSection = document.getElementById("results");

const renderDetails = (data) => {
  if (document.querySelector("movieDetails")) {
    document.querySelector("movieDetails").innerHTML = null;
  }
  const {
    Poster,
    Plot,
    Director,
    BoxOffice,
    imdbRating,
    Runtime,
    Genre,
    Actors,
    Country,
  } = data;
  const div = document.createElement("div");
  const posterImg = document.createElement("img");
  posterImg.classList.add("posterImg");
  const paragraph = document.createElement("p");
  paragraph.classList.add("paragraph");
  const span_director = document.createElement("span");
  const span_box_office = document.createElement("span");
  posterImg.src = Poster;
  paragraph.innerHTML = ` Plot:<span class="plot"> ${Plot} </span>
  <p>Director:<span class="director"> ${Director}</span></p>
  <p>BoxOffice:<span class="boxOffice"> ${BoxOffice} </span></p>
  <p>IMDB:<span class="IMDB"> ${imdbRating} / 10 </span></p>
  <p>Runtime:<span class="Runtime"> ${Runtime} </span></p>
  <p>Genre:<span class="Genre"> ${Genre} </span></p>
  <p>Actors:<span class="Actors"> ${Actors} </span></p>
  <p>Country:<span class="Country"> ${Country} </span></p>`;
  div.classList.add("movieDetails");
  moviesSection.append(posterImg, paragraph, span_director, span_box_office);
};

const showMore = (event) => {
  if (event.target && event.target.id) {
    fetch(`https://www.omdbapi.com/?i=${event.target.id}&apikey=${apiKey}`)
      .then((response) => response.json())
      .then((details) => {
        console.log(details);
        renderDetails(details);
      });
  }
};

moviesSection.addEventListener("click", showMore);

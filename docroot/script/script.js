
var slideIndex = 1;
//showSlides(slideIndex);

function plusSlides(n) {
  showSlides(slideIndex += n);
}

function currentSlide(n) {
  showSlides(n);
}

function showSlides(n) {
  var i;
  var slides = document.getElementsByClassName("mySlides");
  var dots = document.getElementsByClassName("dot");


    console.log("dots lengt: "+dots.length);
    console.log("slides lengt: "+slides.length);
    console.log(slides[n].id);
    console.log("Slide index: "+slideIndex);
    console.log("n index: " + n);



  if (n > slides.length) {slideIndex = 1}
  if (n < 1) {slideIndex = slides.length}



  for (i = 0; i < slides.length; i++) {
      slides[i].style.display = "none";
      console.log("i : " + i);
  }


  for (i = 0; i < dots.length; i++) {
      dots[i].className = dots[i].className.replace(" active", "");
  }
  dots[n].className += " active";

  slides[n].style.display = "block";






//  setTimeout(function(){
//      n++;
//      if( n > 3 ) n = 0;
//      showSlides(n);
//  },3000);
}


function consolelogname(n) {
  console.log(n);
}

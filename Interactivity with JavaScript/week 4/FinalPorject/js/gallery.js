/*Name this external file gallery.js*/
let resultDiv = document.getElementById("image");
let ResultDivTextBeforeHover = resultDiv.textContent;
let Images=document.querySelectorAll("img");

window.onload=function () { 

	Images.forEach((img,index)=>{

		img.setAttribute("tabindex",index+1); 
	})


 }
 function handleImageFocus(img) {
	upDate(img);
	
  }
  function handelImageBlur(){
	  unDo(); 
  }

 

function upDate(previewPic) {
	resultDiv.style.backgroundImage = `url(${previewPic.src})`;
	resultDiv.innerHTML = previewPic.alt;
}

function unDo() {
	resultDiv.style.backgroundImage = "unset";
	resultDiv.innerHTML = ResultDivTextBeforeHover;
}

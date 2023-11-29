/*Name this external file gallery.js*/
let resultDiv = document.getElementById("image");
let ResultDivTextBeforeHover = resultDiv.textContent;

function upDate(previewPic) {
	resultDiv.style.backgroundImage = `url(${previewPic.src})`;
	resultDiv.innerHTML = previewPic.alt;
}

function unDo() {
	resultDiv.style.backgroundImage = "unset";
	resultDiv.innerHTML = ResultDivTextBeforeHover;
}

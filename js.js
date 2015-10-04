// Canvases (temporary used for drawing circle mouse indicator)
var canvas;
var outerCanvas;
var ctx;
var outerCtx;

// Canvas dimension information
var imageLength = 28;
var scale = 20;

// Drawing variables
var lastMousePos;
var mousePos;
var mouseDown = false;
var userPen;

function startDigitRecognition() {

	// Create black background for canvas
	canvas = document.getElementById("digitCanvas");
	if(canvas.getContext)
		ctx = canvas.getContext("2d");
	resetCanvas();

	// Get outer canvas
	outerCanvas = document.getElementById("outerCanvas");
    if(outerCanvas.getContext)
        outerCtx = outerCanvas.getContext('2d');

	// Set drawing pen properties
	userPen      = {colour: "#FFFFFF", thickness:36};
    ctx.lineJoin = "round";
    ctx.lineCap  = "round";

    // Setup event listeners on outer canvas
    outerCanvas.addEventListener('mousemove', function(evt) {
        mousePos = getMousePos(outerCanvas, evt);
        mouseMove(evt);
    });

    outerCanvas.addEventListener("mousedown", function(evt) {
        mouseDownEvt(evt);
    });

    outerCanvas.addEventListener("mouseup", function(evt) {
        mouseUp(evt);
    });

    outerCanvas.addEventListener("touchmove", function(evt) {
        mousePos = getMousePos(outerCanvas, evt.touches[0]);
        mouseMove(evt);
        evt.preventDefault();
    });

    outerCanvas.addEventListener("touchstart", function(evt) {
        mousePos = getMousePos(outerCanvas, evt.touches[0]);
        mouseDownEvt(evt);
        evt.preventDefault();
    });

    outerCanvas.addEventListener("touchend", function(evt) {
        mouseUp(evt);
        evt.preventDefault();
    });
}

function getMousePos(canvas, evt) {
    var rect = canvas.getBoundingClientRect();
    return {
        x: evt.clientX - rect.left,
        y: evt.clientY - rect.top
    };
}

function mouseMove(evt) {
	var colour = userPen.colour;
	clearCtx(outerCtx);
	outerCtx.fillStyle = colour;
    outerCtx.strokeStyle = "black";
    outerCtx.lineWidth = 1;
    drawCircle(outerCtx, mousePos, userPen.thickness/2);
    drawCircleOutline(outerCtx, mousePos, userPen.thickness/2);
    if (mouseDown) {
    	ctx.fillStyle   = colour;
        drawCircle(ctx, mousePos, userPen.thickness/2);
        lastMousePos = mousePos;
    }
}

function mouseDownEvt(evt) {
	mouseDown    = true;
	lastMousePos = mousePos;
}

function mouseUp(evt) {
	mouseDown = false;
}

function drawCircle(ctx, centre, radius) {
    ctx.beginPath();
    ctx.arc(centre.x, centre.y, radius, 0, 2 * Math.PI)
    ctx.fill();
}

function drawCircleOutline(ctx, centre, radius) {
    ctx.beginPath();
    ctx.arc(centre.x, centre.y, radius, 0, 2 * Math.PI)
    ctx.stroke();
}

function clearCtx(ctx) {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
}

function resetCanvas() {
	clearCtx(ctx);
	ctx.fillStyle = "#000000";
	ctx.fillRect(0,0,imageLength*scale,imageLength*scale);
}

function shrinkDownImage() {
	var imageData = ctx.getImageData(0, 0, imageLength*scale, imageLength*scale);
	var data = imageData.data;
	var processedData = Array.apply(null, Array(imageLength*imageLength)).map(Number.prototype.valueOf,0);
	for (var i = 0; i < data.length; i += 4) {
		row = imageLength * Math.floor(i / (imageLength*scale*scale*4));
		column = Math.floor((i % (imageLength*scale*4)) / (scale*4));
		mappedPixelIndex = row + column;
		processedData[mappedPixelIndex] += data[i];
	}
	for (var i = 0; i < processedData.length; i++) {
		processedData[i] = Math.round(processedData[i] / (scale*scale));
	}
	
	for (var i = 0; i < data.length; i += 1) {
		row = imageLength * Math.floor(i / (imageLength*scale*scale*4));
		column = Math.floor((i % (imageLength*scale*4)) / (scale*4));
		mappedPixelIndex = row + column;
		data[i] = processedData[mappedPixelIndex];
	}
	ctx.putImageData(imageData, 0, 0);
	
}

window.onload = startDigitRecognition;
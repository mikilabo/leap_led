/**
 * Initialize
 */
var leapjs = require('leapjs'),
	serialport = require('serialport');

// XBee Port setting
var portName = '/dev/cu.usbserial-AD0267I2';

//Serialport initialize
var sp = new serialport.SerialPort(portName, {
    baudRate: 38400,
    parser: serialport.parsers.readline("\n"),
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false,
});

/**
 * leapmotion controller
 */
var leap = new leapjs.Controller({
  enableGestures: true,
  frameEventName: 'deviceFrame'
});
leap.connect();

/**
 * Send Serialdata to Arduino
 */
var last = "";
function send_data(data){
	if(data == last ){
		console.log("no send");
		return;
	}

	sp.write(data + "\n", function(err, results) {
        //console.log('bytes written: ', results);
        console.log("data = " + data);
    });

	last = data;
}

//frame info from leap motion
var counter = 0;
leap.on("frame", function(frame) {
	counter ++;
	if(counter < 10 ){
		return;
	}
	counter = 0;

	//no hand -> return
	if( frame.hands.length < 1 ){
		//console.log("no hand");
		send_data("0");
		return ;
	}

	var hand = frame.hands[0];

	//getting hand normal vector
	var x_norm = hand.palmNormal[0];
    var y_norm = hand.palmNormal[1];
    var z_norm = hand.palmNormal[2];
    console.log("x_norm= " + x_norm + ",  y_norm = " + y_norm + ", z_norm= " + z_norm);

    if( Math.abs(x_norm) > 0.3 && Math.abs(z_norm) > 0.3  ){
		// up down & right left
		if( z_norm > 0 && x_norm > 0  ){
			console.log("down left");
			send_data("dl");
		}else if( z_norm > 0 && x_norm < 0  ){
			console.log("down right");
			send_data("dr");
		}else if( z_norm < 0 && x_norm > 0  ){
			console.log("up left");
			send_data("ul");
		}else if( z_norm < 0 && x_norm < 0  ){
			console.log("up right");
			send_data("ur");
		}

	}else if( Math.abs(x_norm) > Math.abs(z_norm) ){
        //right left control

        if( x_norm <= -0.3 ){
            //sends right direction
            console.log("---> right");
			send_data("r");
        }else if( x_norm >= 0.3 ){
            //sends left direction
            console.log("---> left");
			send_data("l");
        }else{
            console.log("--->level");
			send_data("h");
        }
    }else{
        //up or down
		if( z_norm <= -0.3 ){
            //sends back direction
            console.log("---> up");
			send_data("u");
        }else if( z_norm >= 0.3 ){
            //sends forward direction
            console.log("---> down ");
			send_data("d");
        }else{
            //sends stop
            console.log("--->level");
			send_data("h");
        }
    }

});

/**
 * for leapmotion
 */

/**
leap.on('ready', function() {
    console.log("leap ready");
});
leap.on('connect', function() {
    console.log("leap connect");
});
leap.on('disconnect', function() {
    console.log("leap disconnect");
});
leap.on('focus', function() {
    console.log("leap focus");
});
leap.on('blur', function() {
    console.log("leap blur");
});
leap.on('streamingStarted', function() {
    console.log("leap streamingStarted");
});
leap.on('streamingStopped', function() {
    console.log("leap streamingStopped");
});

**/

/**
//serialport close
sp.on('close', function(err) {
    console.log('serialport closed');
});

//serialport open
sp.open(function () {
  console.log('serialport open');
});
**/


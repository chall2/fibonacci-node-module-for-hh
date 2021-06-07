var addon = require('./build/Release/test');  

setInterval(()=>{
	console.log(addon.GetNextFibonacciNumber());
},1000);

console.log("Started!"); 
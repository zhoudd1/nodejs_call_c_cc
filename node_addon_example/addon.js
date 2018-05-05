var addon = require('bindings')('addon');

var user_info = {
	"user_name":"zdd",
	"passwd":"123",
	"dev_id":"65535",
}

var obj = addon(user_info.user_name,user_info.passwd,user_info.dev_id);

console.log(obj.lon);
console.log(obj.lat);


module.exports.obj = obj;
module.exports.user_info = user_info;


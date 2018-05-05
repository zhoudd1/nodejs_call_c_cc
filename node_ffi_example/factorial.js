var ffi = require('./node-ffi/')
var refStruct = require('ref-struct');
var refArray = require('ref-array');
var ref = require('ref');

//gps date struct
var gps = refStruct({
	'lon':ref.types.double,
	'lat':ref.types.double,
});

var gpsStructArrayType = refArray(gps);
var gps_info = gpsStructArrayType(1);

//user date struct
var user_info_t = refStruct({
	'user_name':'string',
	'passwd':'string',
	'dev_id':'string',
});

var userStructArrayType = refArray(user_info_t);
var user_info = userStructArrayType(1);


//define c rountine
var libfactorial = ffi.Library('./libfactorial', {
  'get_gps_info': [ gpsStructArrayType, [ 'void' ] ],
  'put_user_info': [ 'void', [ userStructArrayType ] ],
});


//get gps info from c process
gps_info = libfactorial.get_gps_info(0)
console.log('get gps lon: ' + gps_info[0].lon)
console.log('get gps lat: ' + gps_info[0].lat)

//put user info to c process
user_info[0].user_name = 'zdd';
user_info[0].passwd = '123';
user_info[0].dev_id = '65535';
libfactorial.put_user_info(user_info)
console.log('put user_name: ' + user_info[0].user_name)
console.log('put passwd: ' + user_info[0].passwd)
console.log('put dev_id: ' + user_info[0].dev_id)

module.exports.gps_info = gps_info;
module.exports.user_info = user_info;
module.exports.libfactorial=libfactorial;



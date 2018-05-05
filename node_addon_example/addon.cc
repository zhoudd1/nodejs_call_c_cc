#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <napi.h>

typedef struct
{
	double lon;
	double lat;
}gps_info_t;

gps_info_t* gps;

typedef struct
{
	char *user_name;
	char *passwd;
	char *dev_id;
}user_info_t;

user_info_t* user;

void get_gps_shm_init(void)
{
	gps = (gps_info_t *)malloc(sizeof(gps_info_t));
}

void put_user_info_shm_init(void)
{
    user = (user_info_t *)malloc(sizeof(user_info_t));
    user->user_name = (char*)malloc(32*sizeof(char));
    user->passwd = (char*)malloc(32*sizeof(char));
    user->dev_id = (char*)malloc(32*sizeof(char));

}

Napi::Object CreateObject(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::Object obj = Napi::Object::New(env);

	gps->lon = 55.5;
	gps->lat = 66.6;

  	obj.Set(Napi::String::New(env, "lon"), gps->lon);
	obj.Set(Napi::String::New(env, "lat"), gps->lat);

	memset(user->user_name, 0, 32); 
	memset(user->passwd, 0, 32); 
	memset(user->dev_id, 0, 32); 
	memcpy(user->user_name, info[0].ToString(), 32);
	memcpy(user->passwd, info[1].ToString(), 32);
	memcpy(user->dev_id, info[2].ToString(), 32);

	printf("recv user_name: %s\n", user->user_name);
	printf("recv passwd: %s\n", user->passwd);
    printf("recv dev_id: %s\n", user->dev_id);


  	return obj;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	get_gps_shm_init();
	put_user_info_shm_init();
  	return Napi::Function::New(env, CreateObject, "createObject");
}

NODE_API_MODULE(addon, Init)

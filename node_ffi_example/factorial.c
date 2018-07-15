#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

#if defined(WIN32) || defined(_WIN32)
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

//gps info 
typedef struct
{
	double lon;
	double lat;
}gps_info_t;
gps_info_t* gps;

//user info
typedef struct
{
	char *user_name;
	char *passwd;
	char *dev_id;
}user_info_t;

EXPORT gps_info_t* get_gps_info(void) {
  gps = (gps_info_t*)malloc(sizeof(gps_info_t));//这里仅测试用，实际就放到初始化的地方去吧
  gps->lon+=1;
  return gps;
}

EXPORT void put_user_info(user_info_t* user_info) {
  printf("get userinfo(user_name):%s \n",user_info->user_name);
  printf("get userinfo(user_name):%s \n",user_info->passwd);
  printf("get userinfo(user_name):%s \n",user_info->dev_id);

}




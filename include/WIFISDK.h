/*
 * @Description: 
 * @Author: chen
 * @Date: 2023-11-29 11:13:11
 * @LastEditors: chen
 * @LastEditTime: 2023-12-04 10:10:01
 */
#ifndef _WLAN_SDK_H_
#define _WLAN_SDK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>  
#include <regex.h>
#include <pthread.h>
#include <unistd.h>
#include "mi_wlan_datatype.h"
#include "mi_wlan.h"


#define MAX_SCAN_RESULTS    64 // Define the maximum number of Wi-Fi networks to scan
#define SSID_MAX_LENGTH     64
#define PASSWORD_MAX_LENGTH 64
// Structure to hold Wi-Fi information
typedef struct 
{
    char SSID[128];
    char BSSID[64];
    char channel[64];
    char signal_strength[64];
    int count;
}WifiInfo;
//WifiInfo wifi_results[MAX_SCAN_RESULTS]; // 保存wifi扫描结果的数组


typedef struct {
    char ssid[SSID_MAX_LENGTH];  // Wi-Fi name (SSID) string
    char password[PASSWORD_MAX_LENGTH];  // Wi-Fi password string
} WifiCredentials;

extern WLAN_HANDLE g_wlanHdl;              // wifi句柄
extern MI_WLAN_InitParams_t g_stParam;     // wifi配置文件路径
extern MI_WLAN_OpenParams_t g_stOpenParam; // wifi模式

/* **********************************************wifi功能************************************************* */

/**
 * @brief 初始化wifi功能
 * @return {*}
 */
void init_wifi(void);


/**
 * @brief 
 * @return {*}
 */
void deinit_wifi(void);



/**
 * @brief 连接一个wifi，并获取状态
 * @param {char} *ssid wifi名称
 * @param {char} *password 密码
 * @param {MI_WLAN_Status_t} *connect_state 连接状态信息结构体，传入NULL不获取连接状态，connect_state.stStaStatus.state状态获取
 * @return {*}
 */
void connect_wifi(const char *ssid, const char *password, MI_WLAN_Status_t *connect_state);


/**
 * @brief 断开当前连接
 * @return {*}
 */
void disconnect_wifi(void);




/**
 * @brief 重启wifi
 * @return {*}
 */
void reset_wifi(void);





/**
 * @brief 从wpa_supplicant.conf中删除指定ssid的相关信息
 * @param {char} *ssid  要删除的ssid
 * @return {*}
 */
void del_from_conf(const char *ssid);


/* *********************************************************************************************** */



/* **********************************************wifi信息************************************************* */


/**
 * @brief 获取已连接的wifi的ssid
 * @return {*}  成功返回wifi的ssid，且需要free()释放堆空间，失败返回NULL
 */
void *get_connected_wifi_name();



/**
 * @brief 对Unicode字符串转译
 * @param {char} *str  待转译字符串
 * @return {*}
 */
void convert_unicode_str(char *str);



/**
 * @brief 扫描wifi列表，存到WifiInfo数组，没有对Unicode转义
 * @param {WifiInfo} *wifi_results WifiInfo类型数组的数组名
 * @param {int} max_results 扫描wifi的最大数量
 * @return {*} 成功返回wifi数量，失败返回-1
 */
int wifi_scan(WifiInfo *wifi_results, int max_results);



/**
 * @brief 扫描wifi列表，存到WifiInfo数组，有对Unicode转义
 * @param {WifiInfo} *wifi_results   WifiInfo类型数组的数组名
 * @param {int} max_results   扫描wifi的最大数量
 * @return {*}
 */
void wifi_scan_and_convert(WifiInfo *wifi_results, int max_results);


/**
 * @brief 输出WiFiInfo数组中的所有ssid
 * @param {WifiInfo} *wifi_info   WifiInfo类型数组的数组名
 * @return {*}
 */
void printf_WifiInfo(WifiInfo *wifi_info);


/* *********************************************************************************************** */


#endif

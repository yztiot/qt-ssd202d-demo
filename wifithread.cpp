#include "wifithread.h"
#include "HeadDefine.h"
const QString wifiStrList = QString("./grepTemp");
WifiInfo wifi_results[MAX_SCAN_RESULTS]; // 保存wifi扫描结果的数组
//WLAN_HANDLE g_wlanHd = -1;
MI_WLAN_Status_t status;

//extern WLAN_HANDLE g_wlanHdl;              // wifi句柄
//extern MI_WLAN_InitParams_t g_stParam;     // wifi配置文件路径
//extern MI_WLAN_OpenParams_t g_stOpenParam; // wifi模式

WiFiThread::WiFiThread()
{

}

WiFiThread::~WiFiThread(){
}

/*搜索wifi，打开wifi进行初始化*/
void WiFiThread::createWifiFile(){
#if QtForArm
    system("ifconfig wlan0 up");
    init_wifi();

    wifiStatus();
    m_bFirstCheck = false;

    wifi_scan_and_convert(wifi_results, MAX_SCAN_RESULTS);

    for(int i = 0; i < wifi_results[0].count; i++){
        int nameLen = strlen(wifi_results[i].SSID);
        qDebug()<<"the wifi name is::"<< wifi_results[i].SSID << "::"<<strlen(wifi_results[i].SSID);
        if(nameLen > 0)
        {
            wifiNameList.append(wifi_results[i].SSID);
        }
    }

    emit wifiNameSig(wifiNameList);
}
#else
#endif

}



void WiFiThread::onConnectWiFiSig(QString wifiName, QString passWord){
#if QtForArm
    m_wifiName = wifiName;
    MI_WLAN_Close(&g_stOpenParam);
    MI_WLAN_Open(&g_stOpenParam);
    qDebug()<<"connect wifi status::"<< m_wifiName;
    connect_wifi(wifiName.toLatin1().data(), passWord.toLatin1().data(), &status);

   wifiStatus();
#else
#endif
}


/*断开当前连接的wifi*/
void WiFiThread::onDisConnectWiFiSig(){
    #if QtForArm
    qDebug()<<"disconnect ::";
    MI_WLAN_Disconnect(g_wlanHdl);
    MI_WLAN_Close(&g_stOpenParam);
    wifiStatus();
    }
#else
#endif
}

void WiFiThread::onCloseWifiSig(){
#if QtForArm
    disconnect_wifi();
  //  deinit_wifi();
    emit closeWiFiThreadSig();
#else
#endif
}

/*检测当前wifi连接的状态*/
void WiFiThread::wifiStatus(){
#if QtForArm
    int retry_count = 30;
    bool connected = false;
    QString name = "";
    char *pt = nullptr;
    while (retry_count > 0)
    {
        usleep(100 * 1000);                    // 休眠100毫秒
        MI_WLAN_GetStatus(g_wlanHdl, &status); // 重新获取wifi状态

        switch (status.stStaStatus.state)
        {
        case WPA_DISCONNECTED:
            printf("Wi-Fi State: 断开连接\r\n");
            break;
        case WPA_INTERFACE_DISABLED:
            printf("Wi-Fi State: 网络接口禁用\r\n");
            break;
        case WPA_INACTIVE:
            printf("Wi-Fi State: 不活跃（wpa_supplicant禁用）\r\n");
            emit disConnectCurrentWiFiSig();
            break;
        case WPA_SCANNING:
            printf("Wi-Fi State: 扫描网络\r\n");
            //   qDebug()<<"正在连接..."; // Clear connection status
            break;
        case WPA_AUTHENTICATING:
            printf("Wi-Fi State: 正在验证\r\n");
            //  lv_label_set_text(node->JoinTxet, "正在验证..."); // Clear connection status
            break;
        case WPA_ASSOCIATING:
            printf("Wi-Fi State: 正在关联\r\n");
            //   lv_label_set_text(node->JoinTxet, "正在连接..."); // Clear connection status
            break;
        case WPA_ASSOCIATED:
            printf("Wi-Fi State: 关联完成\r\n");
            connected = true;
            pt = (char *)get_connected_wifi_name();
            printf("current Wi-Fi name: %s\n", pt);
            m_wifiName = pt;
            retry_count = -0;
            emit wifiConnectSuccessfulSig(m_wifiName);
            //    lv_label_set_text(node->JoinTxet, "获取IP地址..."); // Clear connection status
            break;
        case WPA_4WAY_HANDSHAKE:
            printf("Wi-Fi State: WPA 4路密钥握手正在进行中\r\n");
            break;
        case WPA_GROUP_HANDSHAKE:
            printf("Wi-Fi State: WPA组密钥握手正在进行中\r\n");
            break;
        case WPA_COMPLETED:
            printf("Wi-Fi State: 连接成功\r\n");
            connected = true;
            pt = (char *)get_connected_wifi_name();
            printf("current Wi-Fi name: %s\n", pt);
            m_wifiName = pt;
            retry_count = -0;
            emit wifiConnectSuccessfulSig(m_wifiName);

            break;
        default:
            break;
        }
        if (connected)
        {
            break; // Exit the loop if connected successfully
        }

        retry_count--;
    }
    if (!m_bFirstCheck && !connected)
    {
        emit disConnectCurrentWiFiSig();
    }
#else
#endif
}

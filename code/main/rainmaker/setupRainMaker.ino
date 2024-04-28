void setupRainMaker(){   

    Node my_node;
    my_node = RMaker.initNode("ESP32 DataHub");

    my_node.addDevice(temperature);
    my_node.addDevice(humidity);
    my_node.addDevice(pressure);
    my_node.addDevice(altitude);

    // This is optional
    RMaker.enableOTA(OTA_USING_TOPICS);
    // If you want to enable scheduling, set time zone for your region using
    // setTimeZone(). The list of available values are provided here
    // https://rainmaker.espressif.com/docs/time-service.html
    //  RMaker.setTimeZone("Asia/Shanghai");
    //  Alternatively, enable the Timezone service and let the phone apps set the
    //  appropriate timezone
    RMaker.enableTZService();

    RMaker.enableSchedule();

    RMaker.enableScenes();
    // Enable ESP Insights. Insteads of using the default http transport, this function will
    // reuse the existing MQTT connection of Rainmaker, thereby saving memory space.
    initAppInsights();

    RMaker.enableSystemService(SYSTEM_SERV_FLAGS_ALL, 2, 2, 2);

    RMaker.start();

    WiFi.onEvent(sysProvEvent);
#if CONFIG_IDF_TARGET_ESP32S2
    WiFiProv.beginProvision(WIFI_PROV_SCHEME_SOFTAP, WIFI_PROV_SCHEME_HANDLER_NONE,
                            WIFI_PROV_SECURITY_1, pop, service_name);
#else
    WiFiProv.beginProvision(WIFI_PROV_SCHEME_BLE, WIFI_PROV_SCHEME_HANDLER_FREE_BTDM,
                            WIFI_PROV_SECURITY_1, pop, service_name);
#endif
}
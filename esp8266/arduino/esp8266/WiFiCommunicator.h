#ifndef INCLUDED_WIFICOMMUNICATOR
#define INCLUDED_WIFICOMMUNICATOR

#include <ESP8266WiFi.h>
#include <memory>

class WiFiCommunicator
{
    public:
        WiFiCommunicator(uint8_t connectionAttempts = 25, bool debug = true) :
            m_connectionAttempts(connectionAttempts),
            m_debug(debug)
        {
            
        }

        bool begin(const String& ssid, const String& password)
        {
            if(m_debug)
            {
                Serial.println("Connecting to " + ssid);
            }
            
            WiFi.mode(WIFI_STA);
            WiFi.begin(ssid.c_str(), password.c_str());

            int attempts = 0;
            
            while(WiFi.status() != WL_CONNECTED)
            {
                attempts ++;
                
                if(m_debug)
                    Serial.print("o");

                if(attempts == m_connectionAttempts)
                    return false;
                    
                delay(500);
            }
            
            return true;
        }

        WiFiClient getClient() const
        {
             return WiFiClient();
        }

        inline IPAddress getIpAddress() const
        {
            return WiFi.localIP();
        }

    private:
        uint8_t m_connectionAttempts;
        bool m_debug;
};

#endif
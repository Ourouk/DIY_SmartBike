#ifndef INCLUDED_MQTTCOMMUNICATOR
#define INCLUDED_MQTTCOMMUNICATOR

#include <memory>
#include <array>
#include "WiFiCommunicator.h"
#include <PubSubClient.h>

class MqttCommunicator : public std::enable_shared_from_this<MqttCommunicator>
{
    public:
        MqttCommunicator(Client& client, String broker, uint16_t port, String id, String topic) :
            m_client(client),
            m_brokerAddress(std::move(broker)),
            m_port(port),
            m_id(std::move(id)),
            m_topic(std::move(topic)),
            m_mqttClient(client)
        {
            
        }

        bool begin()
        {
            m_mqttClient.setServer(m_brokerAddress.c_str(), m_port);
            return true;
        }

        bool connect()
        {
            if(isConnected())
            {
                return true;
            }
            
            Serial.println("Connecting to Broker as " + m_id);
            if (!m_mqttClient.connect(m_id.c_str()))
            {
                Serial.println("Could not connect to broker");
                return false;
            }
            
            Serial.println("Connected to " + m_brokerAddress + " on " + m_topic);
            return true;
        }

        inline bool isConnected()
        {
            return m_mqttClient.connected();
        }

        void update()
        {
            if(!isConnected())
            {
                connect();
            }

            m_mqttClient.loop();
        }

        void publish(const String& message)
        {
            Serial.println("Publishing " + message + " on " + m_topic + " (" + m_brokerAddress + ":" + m_port + ")");
            m_mqttClient.publish(m_topic.c_str(), message.c_str());
        }
        
    private:
        Client& m_client;
        PubSubClient m_mqttClient;
        String m_brokerAddress;
        uint16_t m_port;
        String m_id;
        String m_topic;
};

#endif
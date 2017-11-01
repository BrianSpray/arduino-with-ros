#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

String incomingMessage;

std_msgs::String outgoingMessage;

void messageCb( const std_msgs::String& toggle_msg){
  incomingMessage = toggle_msg.data;
  if (incomingMessage == "ledoff") {  
    digitalWrite(13, LOW);   // blink the led
  } else {
    digitalWrite(13, HIGH);
  }
}


ros::Subscriber<std_msgs::String> sub("toggle_led", &messageCb );
ros::Publisher ledValue("ledvalue", &outgoingMessage);

void setup()
{
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(ledValue);
}

void loop()
{
  if (digitalRead(13) == LOW) {
    outgoingMessage.data = "Led is off";
  } else {
    outgoingMessage.data = "Led is on";
  }
  ledValue.publish(&outgoingMessage);
  nh.spinOnce();
  delay(1000);
}

# Ros/Ros2
## Task
使用Ros或者Ros2搭建一个通信框架(python,cpp都可以)
## Requirement
1.建立一个`camera_node`的node，node的主要目标是获得摄像头的图像数据，与一个获得图片的时候的时间戳，并发布。自行建立一个数据包格式，数据包包含图像数据与时间戳。
2.建立一个`find_red_node`，node订阅`camera_node`发布的话题，并数出图像中，红色物体的个数，将帧率与时间戳输出到imshow的图片的左上角。
3.建立一个`serial_node`，node订阅`find_red_node`发布的话题，并将红色物体个数输出至一个不执行程序的空白终端。
## tips
1.ros/ros2框架的话题发布与订阅。
2.opencv基本使用（转换色域，滑动条，寻找轮廓，滤波去噪）
3.linux的文件思想，伪终端。

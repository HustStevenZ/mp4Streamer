1.概述
   live_ex在开源流媒体服务器live555的基础上，扩展了对avi、mp4两种文件格式的支持，媒体编码格式支持mp3、aac、mpeg4、h264，文件格式的解析由ffmpeg库实现。

2.注意
1).测试使用的live555版本为live.2011.11.20。
2).测试发现，使用vlc播放avi或者mp4中的mpeg4视频时，非常卡，cpu会达到100%，但是使用ffplay和mplayer时播放正常。
3).对于h264视频格式,码率较大时，可能需要增大SEI数据默认的最大长度，如下
打开livemedia\H264VideoStreamFramer.cpp,找到代码行：
#define SEI_MAX_SIZE 5000 // larger than the largest possible SEI NAL unit
建议编译时，将此值修改为10000。


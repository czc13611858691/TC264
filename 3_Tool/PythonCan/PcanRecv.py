import can


def receiveCan():
    # 等待5s是否能接受到消息，不能返回Noe,接收到的消息存储进msg
    msg = bus.recv(20)
    if msg is not None:
        print(msg.arbitration_id)
    else:
        print("not receive msg")


# 目前没有观察到比较好的清空接收缓冲区的方法，只能用重新打开的方式清空已经接收到的rx数据
def clearRxBuf():
    bus = can.interface.Bus(bustype='pcan',
                            channel='PCAN_USBBUS1',
                            bitrate=250000)
    bus.shutdown()
    bus = can.interface.Bus(bustype='pcan',
                            channel='PCAN_USBBUS1',
                            bitrate=250000)


if __name__ == '__main__':
    bus = can.interface.Bus(bustype='pcan',
                            channel='PCAN_USBBUS1',
                            bitrate=250000)
    receiveCan()
    receiveCan()
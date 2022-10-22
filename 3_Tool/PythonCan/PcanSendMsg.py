import can


def send_one():
    bus = can.interface.Bus(bustype='pcan',
                            channel='PCAN_USBBUS1',
                            bitrate=250000)

    msg = can.Message(arbitration_id=0x123,
                      data=[0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77])

    try:
        bus.send(msg, timeout=1)
        print("Message sent on {}".format(bus.channel_info))
    except can.CanError:
        print("Message NOT sent")


if __name__ == '__main__':
    send_one()
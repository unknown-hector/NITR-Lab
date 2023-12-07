import xml.etree.ElementTree as ET

flowmon_file = "AODV.flowmon"

with open(flowmon_file, "r") as file:
    xml_data = file.read()

root = ET.fromstring(xml_data)

flow_stats = root.find("FlowStats")

for flow in flow_stats.findall("Flow"):
    flow_id = flow.get("flowId")
    source_address = flow.get("sourceAddress")  
    destination_address = flow.get("destinationAddress")
    time_first_tx = flow.get("timeFirstTxPacket")
    time_first_rx = flow.get("timeFirstRxPacket")
    tx_bytes = flow.get("txBytes")
    rx_bytes = flow.get("rxBytes")
    tx_packets = flow.get("txPackets")
    rx_packets = flow.get("rxPackets")
    lost_packets = flow.get("lostPackets")
    delay_sum = flow.get("delaySum")

    delay_sum_numeric, delay_sum_unit = delay_sum.split("ns")
    delay_sum_numeric = float(delay_sum_numeric)

    time_first_tx_numeric, time_first_tx_unit = time_first_tx.split("ns")
    time_first_tx_numeric = float(time_first_tx_numeric) / 1e9

    time_first_rx_numeric, time_first_rx_unit = time_first_rx.split("ns")
    time_first_rx_numeric = float(time_first_rx_numeric) / 1e9

# Check for divide-by-zero and calculate flow bit rates, delay mean, and packet loss ratio
    tx_bitrate = int(tx_bytes) * 8 / time_first_tx_numeric if time_first_tx_numeric != 0 else 0  # in bits per second
    rx_bitrate = int(rx_bytes) * 8 / time_first_rx_numeric if time_first_rx_numeric != 0 else 0  # in bits per second
    delay_mean = delay_sum_numeric / int(rx_packets) if int(rx_packets) != 0 else 0  # in nanoseconds
    packet_loss_ratio = int(lost_packets) / int(tx_packets) if int(tx_packets) != 0 else 0



    print(f"Flow ID: {flow_id}")
    print(f"Source Address: {source_address}")
    print(f"Destination Address: {destination_address}")
    print(f"TX Bitrate: {tx_bitrate} bps")
    print(f"RX Bitrate: {rx_bitrate} bps")
    print(f"Delay Mean: {delay_mean} ns")
    print(f"Packet Loss Ratio: {packet_loss_ratio}")
    print("\n")

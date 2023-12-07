import xml.etree.ElementTree as ET


# Define the path to your .flowmon file
flowmon_file = "DSDV.flowmon"

# Read the content of the .flowmon file
with open(flowmon_file, "r") as file:
    xml_data = file.read()

root = ET.fromstring(xml_data)

# Extract information from the XML structure
flow_stats = root.find("FlowStats")
ipv4_flow_classifier = root.find("Ipv4FlowClassifier")

# Process FlowStats
for flow in flow_stats.findall("Flow"):
    flow_id = flow.get("flowId")
    time_first_tx = flow.get("timeFirstTxPacket")
    time_first_rx = flow.get("timeFirstRxPacket")
    # ... you can extract other attributes as needed

    print(f"Flow ID: {flow_id}")
    print(f"Time First Tx: {time_first_tx}")
    print(f"Time First Rx: {time_first_rx}")
    # ... print other attributes or perform further processing

# Process Ipv4FlowClassifier
for flow in ipv4_flow_classifier.findall("Flow"):
    flow_id = flow.get("flowId")
    source_address = flow.get("sourceAddress")
    destination_address = flow.get("destinationAddress")
    # ... you can extract other attributes as needed

    print(f"Flow ID: {flow_id}")
    print(f"Source Address: {source_address}")
    print(f"Destination Address: {destination_address}")
    # ... print other attributes or perform further processing

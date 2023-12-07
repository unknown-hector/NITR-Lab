#include <iostream>
#include <fstream>

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/csma-module.h"
#include "ns3/applications-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/netanim-module.h"
using namespace ns3;

NS_LOG_COMPONENT_DEFINE("CsmaOneSubnetExample");

int main(int argc, char *argv[])
{
#if 0
    LogComponentEnable("CsmaOneSubnetExample", LOG_LEVEL_INFO);
#endif

    CommandLine cmd;
    cmd.Parse(argc, argv);

    NodeContainer nodes;
    nodes.Create(4);

    CsmaHelper csma;
    csma.SetChannelAttribute("DataRate", DataRateValue(DataRate(5000000)));
    csma.SetChannelAttribute("Delay", TimeValue(MilliSeconds(2)));

    NetDeviceContainer devices = csma.Install(nodes);

    InternetStackHelper internet;
    internet.Install(nodes);

    Ipv4AddressHelper ipv4;
    ipv4.SetBase("10.1.1.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces = ipv4.Assign(devices);

    uint16_t port = 9;

    OnOffHelper onoff("ns3::UdpSocketFactory",
                      Address(InetSocketAddress(interfaces.GetAddress(1), port)));
    onoff.SetConstantRate(DataRate("500kb/s"));

    ApplicationContainer app = onoff.Install(nodes.Get(0));
    app.Start(Seconds(1.0));
    app.Stop(Seconds(10.0));

    PacketSinkHelper sink("ns3::UdpSocketFactory",
                          Address(InetSocketAddress(Ipv4Address::GetAny(), port)));
    app = sink.Install(nodes.Get(1));
    app.Start(Seconds(0.0));

    onoff.SetAttribute("Remote", AddressValue(InetSocketAddress(interfaces.GetAddress(0), port)));
    app = onoff.Install(nodes.Get(3));
    app.Start(Seconds(1.1));
    app.Stop(Seconds(10.0));

    app = sink.Install(nodes.Get(0));
    app.Start(Seconds(0.0));

    AsciiTraceHelper ascii;
    csma.EnableAsciiAll(ascii.CreateFileStream("csma-one-subnet.tr"));
    csma.EnablePcapAll("csma-one-subnet_pcap", false);
      AnimationInterface anim("csma-one-subnet.xml");
    

 
    Simulator::Run();
    Simulator::Destroy();
}

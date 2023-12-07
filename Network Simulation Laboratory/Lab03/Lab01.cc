/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/netanim-module.h"

// Default Network Topology
//
//       10.1.1.0
// n0 -------------- n1
//    point-to-point
//
 
using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("FirstScriptExample");

int main (int argc, char *argv[])
{
  CommandLine cmd (__FILE__);
  cmd.Parse (argc, argv);
  
  Time::SetResolution (Time::NS);
  LogComponentEnable ("UdpEchoClientApplication", LOG_LEVEL_INFO);
  LogComponentEnable ("UdpEchoServerApplication", LOG_LEVEL_INFO);

  NodeContainer nodes;
  nodes.Create (5);
  
  AnimationInterface anim("first.xml");
  anim.SetConstantPosition(nodes.Get(0),10.0,10.0);
  anim.SetConstantPosition(nodes.Get(1),20.0,20.0);
  anim.SetConstantPosition(nodes.Get(2),20.0,35.0);
  anim.SetConstantPosition(nodes.Get(3),00.0,35.0);
  anim.SetConstantPosition(nodes.Get(4),00.0,20.0);

  

  PointToPointHelper pointToPoint;
  pointToPoint.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
  pointToPoint.SetChannelAttribute ("Delay", StringValue ("2ms"));

  NetDeviceContainer devices;
  
  devices.Add(pointToPoint.Install(nodes.Get(0), nodes.Get(1)));
  devices.Add(pointToPoint.Install(nodes.Get(1), nodes.Get(2)));
  devices.Add(pointToPoint.Install(nodes.Get(2), nodes.Get(3)));
  devices.Add(pointToPoint.Install(nodes.Get(3), nodes.Get(4)));
  devices.Add(pointToPoint.Install(nodes.Get(4), nodes.Get(0)));

  // devices.Add(pointToPoint.Install(nodes.Get(0), nodes.Get(1)));


  InternetStackHelper stack;
  stack.Install (nodes);

  Ipv4AddressHelper address;
  address.SetBase ("10.1.1.0", "255.255.255.0");

  Ipv4InterfaceContainer interfaces = address.Assign (devices);

  UdpEchoServerHelper echoServer (9);

  ApplicationContainer serverApps = echoServer.Install (nodes.Get (1));
  serverApps.Start (Seconds (1.0));
  serverApps.Stop (Seconds (10.0));

  UdpEchoClientHelper echoClient (interfaces.GetAddress (1), 9);
  echoClient.SetAttribute ("MaxPackets", UintegerValue (1));
  echoClient.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
  echoClient.SetAttribute ("PacketSize", UintegerValue (1024));


  ApplicationContainer clientApps = echoClient.Install (nodes.Get (0));
  ApplicationContainer clientApps1 = echoClient.Install (nodes.Get (2));
  ApplicationContainer clientApps2 = echoClient.Install (nodes.Get (3));
  ApplicationContainer clientApps3 = echoClient.Install (nodes.Get (4));
  clientApps.Start (Seconds (2.0));
  clientApps.Stop (Seconds (4.0));
  clientApps1.Start (Seconds (4.0));
  clientApps1.Stop (Seconds (6.0));
  clientApps2.Start (Seconds (6.0));
  clientApps2.Stop (Seconds (8.0));
  clientApps3.Start (Seconds (8.0));
  clientApps3.Stop (Seconds (10.0));



  AsciiTraceHelper ascii;
  pointToPoint.EnableAsciiAll(ascii.CreateFileStream("first.tr"));


  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}

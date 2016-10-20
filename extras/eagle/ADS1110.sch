<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.2.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="5" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="6" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="2" fill="1" visible="no" active="no"/>
<layer number="53" name="tGND_GNDA" color="7" fill="1" visible="no" active="no"/>
<layer number="54" name="bGND_GNDA" color="7" fill="1" visible="no" active="no"/>
<layer number="56" name="wert" color="7" fill="1" visible="no" active="no"/>
<layer number="57" name="tCAD" color="7" fill="1" visible="no" active="no"/>
<layer number="59" name="tCarbon" color="7" fill="1" visible="no" active="no"/>
<layer number="60" name="bCarbon" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="99" name="SpiceOrder" color="7" fill="1" visible="yes" active="yes"/>
<layer number="100" name="Muster" color="7" fill="1" visible="yes" active="yes"/>
<layer number="101" name="Patch_Top" color="7" fill="1" visible="yes" active="yes"/>
<layer number="102" name="Vscore" color="7" fill="1" visible="yes" active="yes"/>
<layer number="103" name="ATT_MISO" color="7" fill="1" visible="yes" active="yes"/>
<layer number="104" name="Name" color="7" fill="1" visible="yes" active="yes"/>
<layer number="105" name="Beschreib" color="7" fill="1" visible="yes" active="yes"/>
<layer number="106" name="BGA-Top" color="7" fill="1" visible="yes" active="yes"/>
<layer number="107" name="BD-Top" color="7" fill="1" visible="yes" active="yes"/>
<layer number="108" name="centerline" color="7" fill="1" visible="yes" active="yes"/>
<layer number="109" name="ref-old" color="11" fill="1" visible="yes" active="yes"/>
<layer number="110" name="ICSP" color="5" fill="1" visible="yes" active="yes"/>
<layer number="111" name="LPC17xx" color="7" fill="1" visible="yes" active="yes"/>
<layer number="112" name="tSilk" color="7" fill="1" visible="yes" active="yes"/>
<layer number="113" name="IDFDebug" color="4" fill="1" visible="yes" active="yes"/>
<layer number="114" name="Badge_Outline" color="7" fill="1" visible="yes" active="yes"/>
<layer number="115" name="ReferenceISLANDS" color="7" fill="1" visible="yes" active="yes"/>
<layer number="116" name="Patch_BOT" color="7" fill="1" visible="yes" active="yes"/>
<layer number="118" name="Rect_Pads" color="7" fill="1" visible="yes" active="yes"/>
<layer number="121" name="_tsilk" color="7" fill="1" visible="yes" active="yes"/>
<layer number="122" name="_bsilk" color="7" fill="1" visible="yes" active="yes"/>
<layer number="123" name="tTestmark" color="7" fill="1" visible="yes" active="yes"/>
<layer number="124" name="bTestmark" color="7" fill="1" visible="yes" active="yes"/>
<layer number="125" name="_tNames" color="7" fill="1" visible="no" active="yes"/>
<layer number="126" name="_bNames" color="7" fill="1" visible="yes" active="yes"/>
<layer number="127" name="_tValues" color="7" fill="1" visible="yes" active="yes"/>
<layer number="128" name="_bValues" color="7" fill="1" visible="yes" active="yes"/>
<layer number="129" name="Mask" color="7" fill="1" visible="yes" active="yes"/>
<layer number="131" name="prix" color="7" fill="1" visible="yes" active="yes"/>
<layer number="132" name="test" color="7" fill="1" visible="yes" active="yes"/>
<layer number="144" name="Drill_legend" color="7" fill="1" visible="no" active="yes"/>
<layer number="150" name="Notes" color="7" fill="1" visible="yes" active="yes"/>
<layer number="151" name="HeatSink" color="7" fill="1" visible="yes" active="yes"/>
<layer number="152" name="_bDocu" color="7" fill="1" visible="yes" active="yes"/>
<layer number="153" name="FabDoc1" color="7" fill="1" visible="yes" active="yes"/>
<layer number="154" name="FabDoc2" color="7" fill="1" visible="yes" active="yes"/>
<layer number="155" name="FabDoc3" color="7" fill="1" visible="yes" active="yes"/>
<layer number="199" name="Contour" color="7" fill="1" visible="no" active="yes"/>
<layer number="200" name="200bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="201" name="201bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="202" name="202bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="203" name="203bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="204" name="204bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="205" name="205bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="206" name="206bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="207" name="207bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="208" name="208bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="209" name="209bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="210" name="210bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="211" name="211bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="212" name="212bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="213" name="213bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="214" name="214bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="215" name="215bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="216" name="216bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="217" name="217bmp" color="18" fill="1" visible="no" active="no"/>
<layer number="218" name="218bmp" color="19" fill="1" visible="no" active="no"/>
<layer number="219" name="219bmp" color="20" fill="1" visible="no" active="no"/>
<layer number="220" name="220bmp" color="21" fill="1" visible="no" active="no"/>
<layer number="221" name="221bmp" color="22" fill="1" visible="no" active="no"/>
<layer number="222" name="222bmp" color="23" fill="1" visible="no" active="no"/>
<layer number="223" name="223bmp" color="24" fill="1" visible="no" active="no"/>
<layer number="224" name="224bmp" color="25" fill="1" visible="no" active="no"/>
<layer number="225" name="225bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="226" name="226bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="227" name="227bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="228" name="228bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="229" name="229bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="230" name="230bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="231" name="231bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="232" name="Eagle3D_PG2" color="14" fill="2" visible="yes" active="yes"/>
<layer number="233" name="Eagle3D_PG3" color="14" fill="4" visible="yes" active="yes"/>
<layer number="248" name="Housing" color="7" fill="1" visible="yes" active="yes"/>
<layer number="249" name="Edge" color="7" fill="1" visible="yes" active="yes"/>
<layer number="250" name="Descript" color="7" fill="1" visible="yes" active="yes"/>
<layer number="251" name="SMDround" color="7" fill="1" visible="yes" active="yes"/>
<layer number="254" name="cooling" color="7" fill="1" visible="yes" active="yes"/>
<layer number="255" name="routoute" color="7" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="TDAR4">
<packages>
<package name="0805">
<wire x1="1" y1="0.6" x2="-1" y2="0.6" width="0" layer="51"/>
<wire x1="1" y1="-0.6" x2="-1" y2="-0.6" width="0" layer="51"/>
<smd name="1" x="-1.16" y="0" dx="1.1" dy="1.3" layer="1" roundness="15"/>
<smd name="2" x="1.16" y="0" dx="1.1" dy="1.3" layer="1" roundness="15"/>
<wire x1="-1" y1="0.6" x2="-1" y2="-0.6" width="0" layer="51"/>
<wire x1="1" y1="0.6" x2="1" y2="-0.6" width="0" layer="51"/>
<text x="0" y="1.4" size="0.8636" layer="25" font="vector" align="center">&gt;NAME</text>
<wire x1="2" y1="0.9" x2="2" y2="-0.9" width="0" layer="49"/>
<wire x1="-2" y1="0.9" x2="-2" y2="-0.9" width="0" layer="49"/>
<wire x1="-2" y1="0.9" x2="2" y2="0.9" width="0" layer="49"/>
<wire x1="-2" y1="-0.9" x2="2" y2="-0.9" width="0" layer="49"/>
<wire x1="-0.36" y1="0.45" x2="0.36" y2="0.45" width="0.2032" layer="21"/>
<wire x1="-0.36" y1="-0.45" x2="0.36" y2="-0.45" width="0.2032" layer="21"/>
</package>
<package name="DIODE_0805">
<wire x1="-0.3" y1="0.45" x2="-0.3" y2="-0.45" width="0.2032" layer="21"/>
<wire x1="1" y1="0.6" x2="-1" y2="0.6" width="0" layer="51"/>
<wire x1="1" y1="-0.6" x2="-1" y2="-0.6" width="0" layer="51"/>
<smd name="C" x="-1.16" y="0" dx="1.1" dy="1.3" layer="1" roundness="15"/>
<smd name="A" x="1.16" y="0" dx="1.1" dy="1.3" layer="1" roundness="15"/>
<wire x1="-1" y1="0.6" x2="-1" y2="-0.6" width="0" layer="51"/>
<wire x1="1" y1="0.6" x2="1" y2="-0.6" width="0" layer="51"/>
<text x="0" y="1.35" size="0.8636" layer="25" font="vector" align="center">&gt;NAME</text>
<wire x1="2" y1="0.9" x2="2" y2="-0.9" width="0" layer="49"/>
<wire x1="-2" y1="0.9" x2="-2" y2="-0.9" width="0" layer="49"/>
<wire x1="-2" y1="0.9" x2="2" y2="0.9" width="0" layer="49"/>
<wire x1="-2" y1="-0.9" x2="2" y2="-0.9" width="0" layer="49"/>
</package>
<package name="SOD-323-DIODE">
<wire x1="-0.9" y1="0.675" x2="0.9" y2="0.675" width="0" layer="51"/>
<wire x1="0.9" y1="0.675" x2="0.9" y2="0.2" width="0" layer="51"/>
<wire x1="0.9" y1="0.2" x2="0.9" y2="-0.2" width="0" layer="51"/>
<wire x1="0.9" y1="-0.2" x2="0.9" y2="-0.675" width="0" layer="51"/>
<wire x1="0.9" y1="-0.675" x2="-0.9" y2="-0.675" width="0" layer="51"/>
<wire x1="-0.9" y1="-0.675" x2="-0.9" y2="-0.2" width="0" layer="51"/>
<smd name="C" x="-1.16" y="0" dx="1.1" dy="1.3" layer="1" roundness="15"/>
<smd name="A" x="1.16" y="0" dx="1.1" dy="1.3" layer="1" roundness="15"/>
<wire x1="-0.9" y1="-0.2" x2="-0.9" y2="0.2" width="0" layer="51"/>
<wire x1="-0.9" y1="0.2" x2="-0.9" y2="0.675" width="0" layer="51"/>
<wire x1="-1.35" y1="-0.2" x2="-1.35" y2="0.2" width="0" layer="51"/>
<wire x1="1.35" y1="-0.2" x2="1.35" y2="0.2" width="0" layer="51"/>
<wire x1="-1.35" y1="0.2" x2="-0.9" y2="0.2" width="0" layer="51"/>
<wire x1="-1.35" y1="-0.2" x2="-0.9" y2="-0.2" width="0" layer="51"/>
<wire x1="0.9" y1="0.2" x2="1.35" y2="0.2" width="0" layer="51"/>
<wire x1="0.9" y1="-0.2" x2="1.35" y2="-0.2" width="0" layer="51"/>
<wire x1="-0.25" y1="0.5" x2="-0.25" y2="-0.5" width="0.2032" layer="21"/>
<text x="0" y="1.4" size="0.8636" layer="25" font="vector" align="center">&gt;NAME</text>
<wire x1="2" y1="0.9" x2="2" y2="-0.9" width="0" layer="49"/>
<wire x1="-2" y1="0.9" x2="-2" y2="-0.9" width="0" layer="49"/>
<wire x1="-2" y1="0.9" x2="2" y2="0.9" width="0" layer="49"/>
<wire x1="-2" y1="-0.9" x2="2" y2="-0.9" width="0" layer="49"/>
</package>
<package name="0805-NL">
<wire x1="1" y1="0.6" x2="-1" y2="0.6" width="0" layer="51"/>
<wire x1="1" y1="-0.6" x2="-1" y2="-0.6" width="0" layer="51"/>
<smd name="1" x="-1.16" y="0" dx="1.1" dy="1.3" layer="1"/>
<smd name="2" x="1.16" y="0" dx="1.1" dy="1.3" layer="1"/>
<wire x1="-1" y1="0.6" x2="-1" y2="-0.6" width="0" layer="51"/>
<wire x1="1" y1="0.6" x2="1" y2="-0.6" width="0" layer="51"/>
<text x="0" y="1.4" size="0.8636" layer="25" font="vector" align="center">&gt;NAME</text>
<wire x1="2" y1="0.9" x2="2" y2="-0.9" width="0" layer="49"/>
<wire x1="-2" y1="0.9" x2="-2" y2="-0.9" width="0" layer="49"/>
<wire x1="-2" y1="0.9" x2="2" y2="0.9" width="0" layer="49"/>
<wire x1="-2" y1="-0.9" x2="2" y2="-0.9" width="0" layer="49"/>
</package>
<package name="SOT-23-3">
<wire x1="-1.5" y1="-0.7" x2="1.5" y2="-0.7" width="0" layer="51"/>
<wire x1="-1.5" y1="0.7" x2="-0.25" y2="0.7" width="0" layer="51"/>
<wire x1="-0.25" y1="0.7" x2="0.25" y2="0.7" width="0" layer="51"/>
<wire x1="0.25" y1="0.7" x2="1.5" y2="0.7" width="0" layer="51"/>
<wire x1="-1.25" y1="-0.25" x2="-1.25" y2="0.5" width="0.2032" layer="21"/>
<wire x1="-1.5" y1="-0.7" x2="-1.5" y2="0.7" width="0" layer="51"/>
<wire x1="1.5" y1="-0.7" x2="1.5" y2="0.7" width="0" layer="51"/>
<text x="0" y="2.7" size="0.8636" layer="25" font="vector" align="center">&gt;NAME</text>
<smd name="2" x="0.95" y="-1.2" dx="0.75" dy="1.3" layer="1" roundness="30"/>
<smd name="1" x="-0.95" y="-1.2" dx="0.75" dy="1.3" layer="1" roundness="30"/>
<smd name="3" x="0" y="1.2" dx="0.75" dy="1.3" layer="1" roundness="30"/>
<wire x1="0.25" y1="0.7" x2="0.25" y2="1.32" width="0" layer="51"/>
<wire x1="-0.25" y1="0.7" x2="-0.25" y2="1.32" width="0" layer="51"/>
<wire x1="1.25" y1="-0.25" x2="1.25" y2="0.5" width="0.2032" layer="21"/>
<wire x1="-1.7" y1="-2.1" x2="-1.7" y2="2.1" width="0" layer="49"/>
<wire x1="1.7" y1="-2.1" x2="1.7" y2="2.1" width="0" layer="49"/>
<wire x1="1.7" y1="-2.1" x2="-1.7" y2="-2.1" width="0" layer="49"/>
<wire x1="1.7" y1="2.1" x2="-1.7" y2="2.1" width="0" layer="49"/>
<wire x1="-0.65" y1="0.5" x2="-1.25" y2="0.5" width="0.2032" layer="21"/>
<wire x1="1.25" y1="0.5" x2="0.65" y2="0.5" width="0.2032" layer="21"/>
<text x="-1.14" y="-1.25" size="0.5" layer="51">1</text>
<text x="0.76" y="-1.25" size="0.5" layer="51">2</text>
<text x="-0.195" y="0.775" size="0.5" layer="51">3</text>
<wire x1="-1.2" y1="-1.32" x2="-1.2" y2="-0.7" width="0" layer="51"/>
<wire x1="-0.7" y1="-1.32" x2="-0.7" y2="-0.7" width="0" layer="51"/>
<wire x1="-1.2" y1="-1.32" x2="-0.7" y2="-1.32" width="0" layer="51"/>
<wire x1="0.7" y1="-1.32" x2="0.7" y2="-0.7" width="0" layer="51"/>
<wire x1="1.2" y1="-1.32" x2="1.2" y2="-0.7" width="0" layer="51"/>
<wire x1="0.7" y1="-1.32" x2="1.2" y2="-1.32" width="0" layer="51"/>
<wire x1="-0.25" y1="1.32" x2="0.25" y2="1.32" width="0" layer="51"/>
</package>
<package name="HEADER_2.54MM_6_PIN_VER">
<pad name="1" x="-6.35" y="2.54" drill="1.1" diameter="1.925"/>
<wire x1="-7.7" y1="3.89" x2="-5" y2="3.89" width="0" layer="51"/>
<wire x1="-5" y1="-3.89" x2="-5" y2="3.89" width="0" layer="51"/>
<wire x1="-7.7" y1="-3.89" x2="-5" y2="-3.89" width="0" layer="51"/>
<wire x1="-7.7" y1="-3.89" x2="-7.7" y2="3.89" width="0" layer="51"/>
<pad name="2" x="-6.35" y="0" drill="1.1" diameter="1.925"/>
<pad name="3" x="-6.35" y="-2.54" drill="1.1" diameter="1.925"/>
<pad name="4" x="6.35" y="-2.54" drill="1.1" diameter="1.925"/>
<pad name="5" x="6.35" y="0" drill="1.1" diameter="1.925"/>
<pad name="6" x="6.35" y="2.54" drill="1.1" diameter="1.925"/>
<wire x1="7.7" y1="-3.89" x2="7.7" y2="3.89" width="0" layer="51"/>
<wire x1="5" y1="-3.89" x2="5" y2="3.89" width="0" layer="51"/>
<wire x1="5" y1="3.89" x2="7.7" y2="3.89" width="0" layer="51"/>
<wire x1="5" y1="-3.89" x2="7.7" y2="-3.89" width="0" layer="51"/>
<text x="-6.63" y="2.18" size="0.8128" layer="51">1</text>
<text x="-6.63" y="-0.36" size="0.8128" layer="51">2</text>
<text x="-6.63" y="-2.9" size="0.8128" layer="51">3</text>
<text x="6.07" y="-2.9" size="0.8128" layer="51">4</text>
<text x="6.07" y="-0.36" size="0.8128" layer="51">5</text>
<text x="6.07" y="2.18" size="0.8128" layer="51">6</text>
</package>
<package name="SOT-457-6">
<wire x1="-0.85" y1="1.55" x2="0.85" y2="1.55" width="0" layer="51"/>
<wire x1="0.85" y1="-1.1" x2="0.85" y2="-0.8" width="0" layer="51"/>
<wire x1="0.85" y1="-0.15" x2="0.85" y2="0.15" width="0" layer="51"/>
<wire x1="0.85" y1="0.8" x2="0.85" y2="1.1" width="0" layer="51"/>
<circle x="-0.35" y="1.12" radius="0.15" width="0" layer="21"/>
<smd name="1" x="-1.3" y="0.95" dx="1.3" dy="0.5" layer="1" roundness="30"/>
<smd name="2" x="-1.3" y="0" dx="1.3" dy="0.5" layer="1" roundness="30"/>
<smd name="3" x="-1.3" y="-0.95" dx="1.3" dy="0.5" layer="1" roundness="30"/>
<smd name="4" x="1.3" y="-0.95" dx="1.3" dy="0.5" layer="1" roundness="30"/>
<smd name="5" x="1.3" y="0" dx="1.3" dy="0.5" layer="1" roundness="30"/>
<smd name="6" x="1.3" y="0.95" dx="1.3" dy="0.5" layer="1" roundness="30"/>
<wire x1="-0.85" y1="1.1" x2="-1.5" y2="1.1" width="0" layer="51"/>
<wire x1="-0.85" y1="0.8" x2="-1.5" y2="0.8" width="0" layer="51"/>
<wire x1="-0.85" y1="0.15" x2="-1.5" y2="0.15" width="0" layer="51"/>
<wire x1="-0.85" y1="-0.8" x2="-1.5" y2="-0.8" width="0" layer="51"/>
<wire x1="-0.85" y1="-0.15" x2="-1.5" y2="-0.15" width="0" layer="51"/>
<wire x1="-0.85" y1="-1.1" x2="-1.5" y2="-1.1" width="0" layer="51"/>
<wire x1="1.5" y1="1.1" x2="0.85" y2="1.1" width="0" layer="51"/>
<wire x1="1.5" y1="0.8" x2="0.85" y2="0.8" width="0" layer="51"/>
<wire x1="1.5" y1="0.15" x2="0.85" y2="0.15" width="0" layer="51"/>
<wire x1="1.5" y1="-0.8" x2="0.85" y2="-0.8" width="0" layer="51"/>
<wire x1="1.5" y1="-0.15" x2="0.85" y2="-0.15" width="0" layer="51"/>
<wire x1="1.5" y1="-1.1" x2="0.85" y2="-1.1" width="0" layer="51"/>
<wire x1="1.5" y1="1.1" x2="1.5" y2="0.8" width="0" layer="51"/>
<wire x1="1.5" y1="0.15" x2="1.5" y2="-0.15" width="0" layer="51"/>
<wire x1="1.5" y1="-0.8" x2="1.5" y2="-1.1" width="0" layer="51"/>
<wire x1="2.2" y1="1.7" x2="-2.2" y2="1.7" width="0" layer="49"/>
<wire x1="2.2" y1="-1.7" x2="-2.2" y2="-1.7" width="0" layer="49"/>
<wire x1="-2.2" y1="1.7" x2="-2.2" y2="-1.7" width="0" layer="49"/>
<wire x1="2.2" y1="1.7" x2="2.2" y2="-1.7" width="0" layer="49"/>
<text x="0" y="2.54" size="0.8636" layer="25" font="vector" rot="R180" align="center">&gt;NAME</text>
<wire x1="-0.85" y1="-1.55" x2="-0.85" y2="-1.1" width="0" layer="51"/>
<wire x1="-0.85" y1="-1.1" x2="-0.85" y2="-0.8" width="0" layer="51"/>
<wire x1="-0.85" y1="-0.8" x2="-0.85" y2="-0.15" width="0" layer="51"/>
<wire x1="-0.85" y1="-0.15" x2="-0.85" y2="0.15" width="0" layer="51"/>
<wire x1="-0.85" y1="0.15" x2="-0.85" y2="0.8" width="0" layer="51"/>
<wire x1="-0.85" y1="0.8" x2="-0.85" y2="1.1" width="0" layer="51"/>
<wire x1="-0.85" y1="1.1" x2="-0.85" y2="1.55" width="0" layer="51"/>
<wire x1="0.85" y1="-1.55" x2="0.85" y2="1.55" width="0" layer="51"/>
<wire x1="-0.85" y1="-1.55" x2="0.85" y2="-1.55" width="0" layer="51"/>
<wire x1="-1.5" y1="-1.1" x2="-1.5" y2="-0.8" width="0" layer="51"/>
<wire x1="-1.5" y1="-0.15" x2="-1.5" y2="0.15" width="0" layer="51"/>
<wire x1="-1.5" y1="0.8" x2="-1.5" y2="1.1" width="0" layer="51"/>
<wire x1="0" y1="1.12" x2="0.4" y2="1.12" width="0.2032" layer="21"/>
<wire x1="-0.4" y1="-1.12" x2="0.4" y2="-1.12" width="0.2032" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="RESISTOR">
<wire x1="-2.54" y1="-0.889" x2="2.54" y2="-0.889" width="0.254" layer="94"/>
<wire x1="2.54" y1="0.889" x2="-2.54" y2="0.889" width="0.254" layer="94"/>
<wire x1="2.54" y1="-0.889" x2="2.54" y2="0.889" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-0.889" x2="-2.54" y2="0.889" width="0.254" layer="94"/>
<text x="-4.94" y="4.5186" size="1.778" layer="95">&gt;NAME</text>
<text x="-5.32" y="1.938" size="1.778" layer="96">&gt;VALUE</text>
<pin name="2" x="5.08" y="0" visible="off" length="short" direction="pas" rot="R180"/>
<pin name="1" x="-5.08" y="0" visible="off" length="short" direction="pas"/>
</symbol>
<symbol name="DIODE_LED">
<text x="-5.162" y="7.562" size="1.778" layer="95">&gt;NAME</text>
<pin name="C" x="-2.54" y="0" visible="off" length="point" direction="pas"/>
<pin name="A" x="2.54" y="0" visible="off" length="point" direction="pas" rot="R180"/>
<text x="-5.526" y="4.688" size="1.778" layer="96">&gt;VALUE</text>
<wire x1="1.27" y1="1.27" x2="-1.27" y2="0" width="0.254" layer="94"/>
<wire x1="-1.27" y1="0" x2="1.27" y2="-1.27" width="0.254" layer="94"/>
<wire x1="-1.27" y1="1.27" x2="-1.27" y2="0" width="0.254" layer="94"/>
<wire x1="-1.27" y1="0" x2="-1.27" y2="-1.27" width="0.254" layer="94"/>
<wire x1="1.27" y1="1.27" x2="1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="1.27" y2="-1.27" width="0.254" layer="94"/>
<wire x1="0.508" y1="2.032" x2="-0.889" y2="3.429" width="0.1524" layer="94"/>
<wire x1="-0.635" y1="1.905" x2="-2.032" y2="3.302" width="0.1524" layer="94"/>
<polygon width="0.1524" layer="94">
<vertex x="-0.889" y="3.429"/>
<vertex x="0" y="3.048"/>
<vertex x="-0.508" y="2.54"/>
</polygon>
<polygon width="0.1524" layer="94">
<vertex x="-2.032" y="3.302"/>
<vertex x="-1.143" y="2.921"/>
<vertex x="-1.651" y="2.413"/>
</polygon>
<wire x1="-2.54" y1="0" x2="-1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.254" layer="94"/>
</symbol>
<symbol name="CAPACITOR_MLCC">
<pin name="C" x="2.54" y="0" visible="off" length="point" direction="pas" rot="R180"/>
<pin name="A" x="-2.54" y="0" visible="off" length="point" direction="pas"/>
<wire x1="0.5" y1="0" x2="2.54" y2="0" width="0.2032" layer="94"/>
<wire x1="-2.54" y1="0" x2="-0.5" y2="0" width="0.2032" layer="94"/>
<text x="-4.988" y="5.88" size="1.778" layer="95">&gt;NAME</text>
<text x="-5.292" y="3.324" size="1.778" layer="96">&gt;VALUE</text>
<rectangle x1="-0.7" y1="-2.1" x2="-0.25" y2="2.1" layer="94"/>
<rectangle x1="0.25" y1="-2.1" x2="0.7" y2="2.1" layer="94"/>
</symbol>
<symbol name="DIODE_ZENER">
<pin name="A" x="5.08" y="0" visible="off" length="short" direction="pas" rot="R180"/>
<pin name="C" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
<text x="-3.772" y="6.3" size="1.778" layer="95">&gt;NAME</text>
<text x="-3.752" y="2.924" size="1.778" layer="96">&gt;VALUE</text>
<wire x1="2.54" y1="1.27" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="2.54" y2="-1.27" width="0.254" layer="94"/>
<wire x1="0" y1="1.27" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="-1.27" width="0.254" layer="94"/>
<wire x1="2.54" y1="1.27" x2="2.54" y2="-1.27" width="0.254" layer="94"/>
<wire x1="0" y1="1.27" x2="0.762" y2="1.27" width="0.254" layer="94"/>
</symbol>
<symbol name="FERRITE_BEAD">
<wire x1="-2.54" y1="-0.889" x2="2.54" y2="-0.889" width="0.254" layer="94"/>
<wire x1="2.54" y1="0.889" x2="-2.54" y2="0.889" width="0.254" layer="94"/>
<wire x1="2.54" y1="-0.889" x2="2.54" y2="0.889" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-0.889" x2="-2.54" y2="0.889" width="0.254" layer="94"/>
<text x="-5.448" y="5.5346" size="1.778" layer="95">&gt;NAME</text>
<text x="-5.32" y="2.446" size="1.778" layer="96">&gt;VALUE</text>
<pin name="2" x="5.08" y="0" visible="off" length="short" direction="pas" rot="R180"/>
<pin name="1" x="-5.08" y="0" visible="off" length="short" direction="pas"/>
<wire x1="-1.9" y1="0" x2="1.9" y2="0" width="0.254" layer="94"/>
</symbol>
<symbol name="LM4040">
<wire x1="-2.54" y1="2.54" x2="-2.54" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-5.08" x2="0" y2="-5.08" width="0.254" layer="94"/>
<wire x1="0" y1="-5.08" x2="2.54" y2="-5.08" width="0.254" layer="94"/>
<wire x1="2.54" y1="-5.08" x2="2.54" y2="2.54" width="0.254" layer="94"/>
<text x="3.81" y="-3.81" size="1.778" layer="96">&gt;VALUE</text>
<pin name="C" x="0" y="5.08" visible="off" length="short" direction="pas" rot="R270"/>
<pin name="A" x="0" y="-7.62" visible="off" length="short" direction="pas" rot="R90"/>
<text x="3.902" y="0.038" size="1.778" layer="95">&gt;NAME</text>
<wire x1="0" y1="2.54" x2="2.54" y2="2.54" width="0.254" layer="94"/>
<wire x1="-2.54" y1="2.54" x2="0" y2="2.54" width="0.254" layer="94"/>
<wire x1="0" y1="2.54" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-2.54" width="0.254" layer="94"/>
<wire x1="0.97" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-0.97" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="0" y2="-2.54" width="0.254" layer="94"/>
<wire x1="0" y1="-2.54" x2="-1.27" y2="-2.54" width="0.254" layer="94"/>
<wire x1="1.024" y1="0" x2="1.444" y2="0.42" width="0.254" layer="94"/>
<wire x1="-1.376" y1="-0.4" x2="-0.956" y2="0.02" width="0.254" layer="94"/>
<text x="1.016" y="3.302" size="1.27" layer="95">1 (C)</text>
<text x="1.27" y="-7.112" size="1.27" layer="95">2 (A)</text>
<wire x1="0" y1="-5.08" x2="0" y2="-2.54" width="0.254" layer="94"/>
</symbol>
<symbol name="IO_HEADER_6_PIN">
<pin name="1" x="-30.48" y="5.08" length="short" rot="R180"/>
<wire x1="-48.26" y1="7.62" x2="-48.26" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-48.26" y1="-7.62" x2="-33.02" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-33.02" y1="-7.62" x2="-33.02" y2="7.62" width="0.254" layer="94"/>
<wire x1="-33.02" y1="7.62" x2="-48.26" y2="7.62" width="0.254" layer="94"/>
<text x="-5.588" y="14.097" size="1.778" layer="95">&gt;NAME</text>
<text x="-5.588" y="9.906" size="1.778" layer="96">&gt;VALUE</text>
<pin name="2" x="-30.48" y="0" length="short" rot="R180"/>
<pin name="3" x="-30.48" y="-5.08" length="short" rot="R180"/>
<wire x1="33.02" y1="7.62" x2="33.02" y2="-7.62" width="0.254" layer="94"/>
<wire x1="33.02" y1="-7.62" x2="48.26" y2="-7.62" width="0.254" layer="94"/>
<wire x1="48.26" y1="-7.62" x2="48.26" y2="7.62" width="0.254" layer="94"/>
<wire x1="48.26" y1="7.62" x2="33.02" y2="7.62" width="0.254" layer="94"/>
<pin name="4" x="30.48" y="-5.08" length="short"/>
<pin name="5" x="30.48" y="0" length="short"/>
<pin name="6" x="30.48" y="5.08" length="short"/>
</symbol>
<symbol name="IC_ADC_ADS1110">
<pin name="VCC" x="12.7" y="0" length="short" direction="pwr" rot="R180"/>
<pin name="VIN+" x="-12.7" y="5.08" length="short"/>
<pin name="VIN-" x="12.7" y="5.08" length="short" rot="R180"/>
<pin name="SCL" x="-12.7" y="-5.08" length="short"/>
<pin name="GND" x="-12.7" y="0" length="short" direction="pwr"/>
<pin name="SDA" x="12.7" y="-5.08" length="short" rot="R180"/>
<wire x1="-10.16" y1="7.62" x2="-10.16" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-7.62" x2="10.16" y2="-7.62" width="0.254" layer="94"/>
<wire x1="10.16" y1="-7.62" x2="10.16" y2="7.62" width="0.254" layer="94"/>
<wire x1="10.16" y1="7.62" x2="-10.16" y2="7.62" width="0.254" layer="94"/>
<text x="-5.08" y="12.7" size="1.778" layer="95">&gt;NAME</text>
<text x="-5.08" y="9.144" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="ERJ-P06F3011V" prefix="R">
<description>PANASONIC SMD RESISTOR THICK FILM 3K01/0.5W, 1%, 100ppm, AEC-Q200, Automotive</description>
<gates>
<gate name="G$1" symbol="RESISTOR" x="0" y="0"/>
</gates>
<devices>
<device name="" package="0805">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ERJ-P06F1001V" prefix="R">
<description>PANASONIC SMD RESISTOR THICK FILM 1K/0.5W, 1%, 100ppm, AEC-Q200, Automotive</description>
<gates>
<gate name="G$1" symbol="RESISTOR" x="0" y="0"/>
</gates>
<devices>
<device name="" package="0805">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="HSMG-C170" prefix="D">
<description>BROADCOM SMD DIODE LED (GREEN), 15mcd, 20mA, 2.2Vf, 170°, Diffused, Standard</description>
<gates>
<gate name="G$1" symbol="DIODE_LED" x="0" y="0"/>
</gates>
<devices>
<device name="" package="DIODE_0805">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="C"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="08055C104J4Z2A" prefix="C">
<description>AVX SMD MLCC 0.1uF/50V, X7R, 5%, Flexible, Automotive</description>
<gates>
<gate name="G$1" symbol="CAPACITOR_MLCC" x="0" y="0"/>
</gates>
<devices>
<device name="" package="0805">
<connects>
<connect gate="G$1" pin="A" pad="1"/>
<connect gate="G$1" pin="C" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="GCJ21BR71H105KA01L" prefix="C">
<description>MURATA SMD MLCC 1uF/50V, X7R, 10%, Flexible, Automotive</description>
<gates>
<gate name="G$1" symbol="CAPACITOR_MLCC" x="0" y="0"/>
</gates>
<devices>
<device name="" package="0805">
<connects>
<connect gate="G$1" pin="A" pad="1"/>
<connect gate="G$1" pin="C" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ERJ-6RBD1002V" prefix="R">
<description>PANASONIC SMD RESISTOR 10K/100mW, 0.5%, 50ppm, AEC-Q200, Automotive</description>
<gates>
<gate name="G$1" symbol="RESISTOR" x="0" y="0"/>
</gates>
<devices>
<device name="" package="0805">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="BZX384" prefix="D">
<description>VISHAY DIODE ZENER 5V1/5V6, 200mW, 2%, AEC-Q101, Automotive

http://www.vishay.com/docs/85764/bzx384.pdf

5V1
MOUSER: BZX384B5V1-HE3-08 / BZX384B5V1-HE3-18 (78-BZX384B5V1-HE3-08 / 78-BZX384B5V1-HE3-18)

5V6
MOUSER: BZX384B5V6-HE3-08 / BZX384B5V6-HE3-18 (78-BZX384B5V6-HE3-08 / 78-BZX384B5V6-HE3-18)</description>
<gates>
<gate name="G$1" symbol="DIODE_ZENER" x="0" y="0"/>
</gates>
<devices>
<device name="B5V6-HE3" package="SOD-323-DIODE">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="C"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="B5V1-HE3" package="SOD-323-DIODE">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="C"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ERJ-6RBD4701V" prefix="R">
<description>PANASONIC SMD RESISTOR 4K7/100mW, 0.5%, 50ppm, AEC-Q200, Automotive</description>
<gates>
<gate name="G$1" symbol="RESISTOR" x="0" y="0"/>
</gates>
<devices>
<device name="" package="0805">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-NL" package="0805-NL">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="BLM21PG220SH1D" prefix="FB">
<description>MURATA FERRITE BEAD 22R @ 100MHz, 6A, EMI Filter Powerlines, AEC-Q200, Automotive</description>
<gates>
<gate name="G$1" symbol="FERRITE_BEAD" x="0" y="0"/>
</gates>
<devices>
<device name="" package="0805">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="LM4040" prefix="IC">
<description>TI SMD IC VOLTAGE REFERENCE SHUNT 2.048V/4.096V, 15mA, 0.1%, AEC-Q100, Automotive

LM4040AIM3-2.0/NOPB      2.048V
LM4040AIM3-4.1/NOPB	    4.096V</description>
<gates>
<gate name="G$1" symbol="LM4040" x="0" y="0"/>
</gates>
<devices>
<device name="AIM3-2.0/NOPB" package="SOT-23-3">
<connects>
<connect gate="G$1" pin="A" pad="2 3"/>
<connect gate="G$1" pin="C" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="AIM3-4.1/NOPB" package="SOT-23-3">
<connects>
<connect gate="G$1" pin="A" pad="2 3"/>
<connect gate="G$1" pin="C" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="HEADER_6_PIN" prefix="J">
<gates>
<gate name="G$1" symbol="IO_HEADER_6_PIN" x="0" y="0"/>
</gates>
<devices>
<device name="" package="HEADER_2.54MM_6_PIN_VER">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ERJ-T06J222V" prefix="R">
<description>PANASONIC SMD RESISTOR THICK FILM 2K2/0.25W, 5%, 200ppm, AEC-Q200, Automotive</description>
<gates>
<gate name="G$1" symbol="RESISTOR" x="0" y="0"/>
</gates>
<devices>
<device name="" package="0805">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ADS1110" prefix="IC">
<description>TEXAS INSTRUMENTS SMD ADC, 16-BIT, 1-CHANNEL, Onboard Reference (2.048V), I2C, Standard

http://www.ti.com/lit/ds/symlink/ads1110.pdf

I2C ADDRESSES:
      Part No.	                 Package                          I2C Address
	                 Marking     	      BIN	    HEX        DEC
ADS1110A0IDBVT	ED0	01001000       0X48	72
ADS1110A1IDBVT	ED1	01001001       0X49	73
ADS1110A2IDBVT	ED2	01001010       0X4A	74
ADS1110A3IDBVT	ED3	01001011       0X4B	75
ADS1110A4IDBVT	ED4	01001100       0X4C	76
ADS1110A5IDBVT	ED5	01001101       0X4D	77
ADS1110A6IDBVT	ED6	01001110       0X4E	78
ADS1110A7IDBVT	ED7	01001111       0X4F	79

MOUSER:
595-ADS1110A0IDBVT (ADS1110A0IDBVT) - 0X48
595-ADS1110A1IDBVT (ADS1110A1IDBVT) - 0X49
595-ADS1110A2IDBVT (ADS1110A2IDBVT) - 0X4A
595-ADS1110A3IDBVT (ADS1110A3IDBVT) - 0X4B
595-ADS1110A4IDBVT (ADS1110A4IDBVT) - 0X4C
595-ADS1110A6IDBVT (ADS1110A6IDBVT) - 0X4E</description>
<gates>
<gate name="G$1" symbol="IC_ADC_ADS1110" x="0" y="0"/>
</gates>
<devices>
<device name="A0IDBVT" package="SOT-457-6">
<connects>
<connect gate="G$1" pin="GND" pad="2"/>
<connect gate="G$1" pin="SCL" pad="3"/>
<connect gate="G$1" pin="SDA" pad="4"/>
<connect gate="G$1" pin="VCC" pad="5"/>
<connect gate="G$1" pin="VIN+" pad="1"/>
<connect gate="G$1" pin="VIN-" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="A1IDBVT" package="SOT-457-6">
<connects>
<connect gate="G$1" pin="GND" pad="2"/>
<connect gate="G$1" pin="SCL" pad="3"/>
<connect gate="G$1" pin="SDA" pad="4"/>
<connect gate="G$1" pin="VCC" pad="5"/>
<connect gate="G$1" pin="VIN+" pad="1"/>
<connect gate="G$1" pin="VIN-" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="A2IDBVT" package="SOT-457-6">
<connects>
<connect gate="G$1" pin="GND" pad="2"/>
<connect gate="G$1" pin="SCL" pad="3"/>
<connect gate="G$1" pin="SDA" pad="4"/>
<connect gate="G$1" pin="VCC" pad="5"/>
<connect gate="G$1" pin="VIN+" pad="1"/>
<connect gate="G$1" pin="VIN-" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="A3IDBVT" package="SOT-457-6">
<connects>
<connect gate="G$1" pin="GND" pad="2"/>
<connect gate="G$1" pin="SCL" pad="3"/>
<connect gate="G$1" pin="SDA" pad="4"/>
<connect gate="G$1" pin="VCC" pad="5"/>
<connect gate="G$1" pin="VIN+" pad="1"/>
<connect gate="G$1" pin="VIN-" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="A4IDBVT" package="SOT-457-6">
<connects>
<connect gate="G$1" pin="GND" pad="2"/>
<connect gate="G$1" pin="SCL" pad="3"/>
<connect gate="G$1" pin="SDA" pad="4"/>
<connect gate="G$1" pin="VCC" pad="5"/>
<connect gate="G$1" pin="VIN+" pad="1"/>
<connect gate="G$1" pin="VIN-" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="A5IDBVT" package="SOT-457-6">
<connects>
<connect gate="G$1" pin="GND" pad="2"/>
<connect gate="G$1" pin="SCL" pad="3"/>
<connect gate="G$1" pin="SDA" pad="4"/>
<connect gate="G$1" pin="VCC" pad="5"/>
<connect gate="G$1" pin="VIN+" pad="1"/>
<connect gate="G$1" pin="VIN-" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="A6IDBVT" package="SOT-457-6">
<connects>
<connect gate="G$1" pin="GND" pad="2"/>
<connect gate="G$1" pin="SCL" pad="3"/>
<connect gate="G$1" pin="SDA" pad="4"/>
<connect gate="G$1" pin="VCC" pad="5"/>
<connect gate="G$1" pin="VIN+" pad="1"/>
<connect gate="G$1" pin="VIN-" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="A7IDBVT" package="SOT-457-6">
<connects>
<connect gate="G$1" pin="GND" pad="2"/>
<connect gate="G$1" pin="SCL" pad="3"/>
<connect gate="G$1" pin="SDA" pad="4"/>
<connect gate="G$1" pin="VCC" pad="5"/>
<connect gate="G$1" pin="VIN+" pad="1"/>
<connect gate="G$1" pin="VIN-" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
<clearance class="0" value="0.355"/>
</class>
</classes>
<parts>
<part name="ADS1110-C-BY-1" library="TDAR4" deviceset="08055C104J4Z2A" device="" value="(100nF/50V, X7R, 5%, 08055C104J4Z2A)"/>
<part name="ADS1110-D-VD" library="TDAR4" deviceset="BZX384" device="B5V1-HE3" value="(5V1/200mW, 2%, BZX384B5V1-HE3)"/>
<part name="ADS1110-R-VD1" library="TDAR4" deviceset="ERJ-6RBD1002V" device="" value="(10K/0.1W, 0.5%, ERJ-6RBD1002V)"/>
<part name="ADS1110-R-VD2" library="TDAR4" deviceset="ERJ-6RBD4701V" device="" value="(4K7/0.1W, 0.5%, ERJ-6RBD4701V)"/>
<part name="ADS1110-C-BY-2" library="TDAR4" deviceset="GCJ21BR71H105KA01L" device="" value="(1uF/50V, X7R, 10%, GCJ21BR71H105KA01L)"/>
<part name="ADS1110-LM4040-FB" library="TDAR4" deviceset="BLM21PG220SH1D" device="" value="(22R@100MHz/6A, BLM21PG220SH1D)"/>
<part name="ADS1110-LM4040-IC" library="TDAR4" deviceset="LM4040" device="AIM3-2.0/NOPB" value="LM4040AIM3-2.0/NOPB"/>
<part name="ADS1110-LM4040-R-VIN" library="TDAR4" deviceset="ERJ-P06F3011V" device="" value="(3K01/0.5W, 1%, ERJ-P06F3011V)"/>
<part name="ADS1110-LM4040-C-BY" library="TDAR4" deviceset="08055C104J4Z2A" device="" value="(100nF/50V, X7R, 5%, 08055C104J4Z2A)"/>
<part name="ADS1110-J1" library="TDAR4" deviceset="HEADER_6_PIN" device="" value="ADS1110 - HEADER 6-PIN"/>
<part name="ADS1110-R-PWR" library="TDAR4" deviceset="ERJ-P06F1001V" device="" value="(1K/0.5W, 1%, ERJ-P06F1001V)"/>
<part name="ADS1110-D-PWR" library="TDAR4" deviceset="HSMG-C170" device="" value="(GREEN, HSMG-C170)"/>
<part name="ADS1110-R-SDA" library="TDAR4" deviceset="ERJ-T06J222V" device="" value="(2K2/0.25W, 5%, ERJ-T06J222V)"/>
<part name="ADS1110-R-SCL" library="TDAR4" deviceset="ERJ-T06J222V" device="" value="(2K2/0.25W, 5%, ERJ-T06J222V)"/>
<part name="ADS1110-IC" library="TDAR4" deviceset="ADS1110" device="A0IDBVT"/>
</parts>
<sheets>
<sheet>
<plain>
<text x="43.688" y="98.044" size="1.778" layer="97">(I2C ADDRESS: 0x48 / 72)</text>
<text x="7.62" y="170.18" size="4.445" layer="97">ADS1110 - VOLTAGE SENSOR</text>
<wire x1="-0.127" y1="180.213" x2="225.933" y2="180.213" width="0.1016" layer="94"/>
<wire x1="225.933" y1="180.213" x2="225.933" y2="-0.127" width="0.1016" layer="94"/>
<wire x1="-0.127" y1="180.213" x2="-0.127" y2="-0.127" width="0.1016" layer="94"/>
<wire x1="-0.127" y1="-0.127" x2="225.933" y2="-0.127" width="0.1016" layer="94"/>
</plain>
<instances>
<instance part="ADS1110-C-BY-1" gate="G$1" x="17.78" y="78.74" smashed="yes" rot="R270">
<attribute name="NAME" x="21.428" y="79.286" size="1.778" layer="95"/>
<attribute name="VALUE" x="20.362" y="75.968" size="1.778" layer="96"/>
</instance>
<instance part="ADS1110-D-VD" gate="G$1" x="177.8" y="134.62" smashed="yes" rot="R270">
<attribute name="NAME" x="181.244" y="134.292" size="1.778" layer="95"/>
<attribute name="VALUE" x="180.744" y="130.546" size="1.778" layer="96"/>
</instance>
<instance part="ADS1110-R-VD1" gate="G$1" x="160.02" y="154.94" smashed="yes" rot="R270">
<attribute name="NAME" x="138.4554" y="156.718" size="1.778" layer="95"/>
<attribute name="VALUE" x="117.094" y="152.908" size="1.778" layer="96"/>
</instance>
<instance part="ADS1110-R-VD2" gate="G$1" x="160.02" y="134.62" smashed="yes" rot="R270">
<attribute name="NAME" x="137.9474" y="135.636" size="1.778" layer="95"/>
<attribute name="VALUE" x="116.84" y="132.08" size="1.778" layer="96"/>
</instance>
<instance part="ADS1110-C-BY-2" gate="G$1" x="83.82" y="76.2" smashed="yes" rot="R90">
<attribute name="NAME" x="87.424" y="78.09" size="1.778" layer="95"/>
<attribute name="VALUE" x="87.256" y="74.638" size="1.778" layer="96"/>
</instance>
<instance part="ADS1110-LM4040-FB" gate="G$1" x="129.54" y="45.72" smashed="yes" rot="R180">
<attribute name="NAME" x="119.52" y="53.5406" size="1.778" layer="95"/>
<attribute name="VALUE" x="108.98" y="49.69" size="1.778" layer="96"/>
</instance>
<instance part="ADS1110-LM4040-IC" gate="G$1" x="195.58" y="30.48" smashed="yes">
<attribute name="VALUE" x="164.846" y="26.67" size="1.778" layer="96"/>
<attribute name="NAME" x="168.24" y="30.264" size="1.778" layer="95"/>
</instance>
<instance part="ADS1110-LM4040-R-VIN" gate="G$1" x="167.64" y="45.72" smashed="yes" rot="R180">
<attribute name="NAME" x="160.414" y="41.8566" size="1.778" layer="95"/>
<attribute name="VALUE" x="149.62" y="38.26" size="1.778" layer="96"/>
</instance>
<instance part="ADS1110-LM4040-C-BY" gate="G$1" x="139.7" y="20.32" smashed="yes" rot="R270">
<attribute name="NAME" x="144.11" y="21.374" size="1.778" layer="95"/>
<attribute name="VALUE" x="143.552" y="18.056" size="1.778" layer="96"/>
</instance>
<instance part="ADS1110-J1" gate="G$1" x="58.42" y="142.24" smashed="yes">
<attribute name="NAME" x="11.176" y="155.829" size="1.778" layer="95"/>
<attribute name="VALUE" x="4.318" y="151.892" size="1.778" layer="96"/>
</instance>
<instance part="ADS1110-R-PWR" gate="G$1" x="165.1" y="83.82" smashed="yes" rot="R90">
<attribute name="NAME" x="168.542" y="85.0366" size="1.778" layer="95"/>
<attribute name="VALUE" x="168.416" y="81.694" size="1.778" layer="96"/>
</instance>
<instance part="ADS1110-D-PWR" gate="G$1" x="165.1" y="96.52" smashed="yes" rot="R90">
<attribute name="NAME" x="169.082" y="97.478" size="1.778" layer="95"/>
<attribute name="VALUE" x="168.972" y="93.588" size="1.778" layer="96"/>
</instance>
<instance part="ADS1110-R-SDA" gate="G$1" x="15.24" y="25.4" smashed="yes" rot="R90">
<attribute name="NAME" x="18.682" y="26.6166" size="1.778" layer="95"/>
<attribute name="VALUE" x="18.556" y="23.274" size="1.778" layer="96"/>
</instance>
<instance part="ADS1110-R-SCL" gate="G$1" x="71.12" y="25.4" smashed="yes" rot="R90">
<attribute name="NAME" x="74.562" y="26.6166" size="1.778" layer="95"/>
<attribute name="VALUE" x="74.436" y="23.274" size="1.778" layer="96"/>
</instance>
<instance part="ADS1110-IC" gate="G$1" x="58.42" y="109.22" smashed="yes">
<attribute name="NAME" x="52.324" y="122.428" size="1.778" layer="95"/>
<attribute name="VALUE" x="49.022" y="118.872" size="1.778" layer="96"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="ADS1110-VCC-FILTERED" class="0">
<segment>
<pinref part="ADS1110-LM4040-R-VIN" gate="G$1" pin="2"/>
<pinref part="ADS1110-LM4040-FB" gate="G$1" pin="1"/>
<wire x1="162.56" y1="45.72" x2="139.7" y2="45.72" width="0.1524" layer="91"/>
<pinref part="ADS1110-LM4040-C-BY" gate="G$1" pin="A"/>
<wire x1="134.62" y1="45.72" x2="139.7" y2="45.72" width="0.1524" layer="91"/>
<wire x1="139.7" y1="45.72" x2="139.7" y2="22.86" width="0.1524" layer="91"/>
<junction x="139.7" y="45.72"/>
</segment>
</net>
<net name="ADS1110-LED-PWR" class="0">
<segment>
<pinref part="ADS1110-D-PWR" gate="G$1" pin="C"/>
<pinref part="ADS1110-R-PWR" gate="G$1" pin="2"/>
<wire x1="165.1" y1="88.9" x2="165.1" y2="93.98" width="0.1524" layer="91"/>
</segment>
</net>
<net name="ADS1110-GND" class="0">
<segment>
<pinref part="ADS1110-LM4040-C-BY" gate="G$1" pin="C"/>
<wire x1="139.7" y1="17.78" x2="139.7" y2="12.7" width="0.1524" layer="91"/>
<junction x="139.7" y="12.7"/>
<label x="131.826" y="9.398" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-LM4040-IC" gate="G$1" pin="A"/>
<wire x1="195.58" y1="17.78" x2="195.58" y2="22.86" width="0.1524" layer="91"/>
<junction x="195.58" y="17.78"/>
<label x="188.526" y="14.108" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-C-BY-1" gate="G$1" pin="C"/>
<wire x1="17.78" y1="76.2" x2="17.78" y2="71.12" width="0.1524" layer="91"/>
<junction x="17.78" y="71.12"/>
<label x="10.16" y="67.056" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-C-BY-2" gate="G$1" pin="A"/>
<wire x1="83.82" y1="73.66" x2="83.82" y2="68.58" width="0.1524" layer="91"/>
<junction x="83.82" y="68.58"/>
<label x="76.454" y="64.77" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-D-VD" gate="G$1" pin="A"/>
<wire x1="177.8" y1="129.54" x2="177.8" y2="124.46" width="0.1524" layer="91"/>
<junction x="177.8" y="124.46"/>
<label x="169.926" y="120.904" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-R-VD2" gate="G$1" pin="2"/>
<wire x1="160.02" y1="129.54" x2="160.02" y2="124.46" width="0.1524" layer="91"/>
<junction x="160.02" y="124.46"/>
<label x="151.638" y="120.904" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-R-PWR" gate="G$1" pin="1"/>
<wire x1="165.1" y1="78.74" x2="165.1" y2="73.66" width="0.1524" layer="91"/>
<junction x="165.1" y="73.66"/>
<label x="157.734" y="69.85" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-J1" gate="G$1" pin="1"/>
<wire x1="33.02" y1="147.32" x2="27.94" y2="147.32" width="0.1524" layer="91"/>
<junction x="33.02" y="147.32"/>
<label x="34.544" y="146.558" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-IC" gate="G$1" pin="GND"/>
<wire x1="45.72" y1="109.22" x2="40.64" y2="109.22" width="0.1524" layer="91"/>
<junction x="40.64" y="109.22"/>
<label x="21.59" y="108.458" size="1.778" layer="95"/>
</segment>
</net>
<net name="ADS1110-SDA" class="0">
<segment>
<pinref part="ADS1110-R-SDA" gate="G$1" pin="1"/>
<wire x1="15.24" y1="20.32" x2="15.24" y2="15.24" width="0.1524" layer="91"/>
<junction x="15.24" y="15.24"/>
<label x="8.128" y="12.192" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-IC" gate="G$1" pin="SDA"/>
<wire x1="76.2" y1="104.14" x2="71.12" y2="104.14" width="0.1524" layer="91"/>
<junction x="76.2" y="104.14"/>
<label x="79.248" y="103.378" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-J1" gate="G$1" pin="5"/>
<wire x1="83.82" y1="142.24" x2="88.9" y2="142.24" width="0.1524" layer="91"/>
<junction x="83.82" y="142.24"/>
<label x="66.802" y="141.478" size="1.778" layer="95"/>
</segment>
</net>
<net name="ADS1110-VIN-" class="0">
<segment>
<junction x="76.2" y="114.3"/>
<pinref part="ADS1110-IC" gate="G$1" pin="VIN-"/>
<wire x1="76.2" y1="114.3" x2="71.12" y2="114.3" width="0.1524" layer="91"/>
<label x="78.486" y="113.538" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-LM4040-R-VIN" gate="G$1" pin="1"/>
<pinref part="ADS1110-LM4040-IC" gate="G$1" pin="C"/>
<wire x1="195.58" y1="35.56" x2="195.58" y2="45.72" width="0.1524" layer="91"/>
<wire x1="203.2" y1="45.72" x2="195.58" y2="45.72" width="0.1524" layer="91"/>
<junction x="195.58" y="45.72"/>
<wire x1="195.58" y1="45.72" x2="172.72" y2="45.72" width="0.1524" layer="91"/>
<junction x="203.2" y="45.72"/>
<label x="204.724" y="44.704" size="1.778" layer="95"/>
</segment>
</net>
<net name="ADS1110-SCL" class="0">
<segment>
<pinref part="ADS1110-R-SCL" gate="G$1" pin="1"/>
<wire x1="71.12" y1="20.32" x2="71.12" y2="15.24" width="0.1524" layer="91"/>
<junction x="71.12" y="15.24"/>
<label x="64.008" y="12.192" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="40.64" y1="104.14" x2="45.72" y2="104.14" width="0.1524" layer="91"/>
<pinref part="ADS1110-IC" gate="G$1" pin="SCL"/>
<junction x="40.64" y="104.14"/>
<label x="23.368" y="103.124" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-J1" gate="G$1" pin="2"/>
<wire x1="33.02" y1="142.24" x2="27.94" y2="142.24" width="0.1524" layer="91"/>
<junction x="33.02" y="142.24"/>
<label x="34.544" y="141.478" size="1.778" layer="95"/>
</segment>
</net>
<net name="ADS1110-VCC" class="0">
<segment>
<pinref part="ADS1110-R-SDA" gate="G$1" pin="2"/>
<wire x1="15.24" y1="30.48" x2="15.24" y2="35.56" width="0.1524" layer="91"/>
<junction x="15.24" y="35.56"/>
<label x="7.62" y="37.592" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-R-SCL" gate="G$1" pin="2"/>
<wire x1="71.12" y1="30.48" x2="71.12" y2="35.56" width="0.1524" layer="91"/>
<junction x="71.12" y="35.56"/>
<label x="62.738" y="37.338" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-LM4040-FB" gate="G$1" pin="2"/>
<wire x1="124.46" y1="45.72" x2="119.38" y2="45.72" width="0.1524" layer="91"/>
<junction x="119.38" y="45.72"/>
<label x="101.854" y="44.958" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-D-PWR" gate="G$1" pin="A"/>
<wire x1="165.1" y1="99.06" x2="165.1" y2="104.14" width="0.1524" layer="91"/>
<junction x="165.1" y="104.14"/>
<label x="157.226" y="105.918" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="83.82" y1="78.74" x2="83.82" y2="83.82" width="0.1524" layer="91"/>
<pinref part="ADS1110-C-BY-2" gate="G$1" pin="C"/>
<junction x="83.82" y="83.82"/>
<label x="75.692" y="85.852" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-C-BY-1" gate="G$1" pin="A"/>
<wire x1="17.78" y1="81.28" x2="17.78" y2="86.36" width="0.1524" layer="91"/>
<junction x="17.78" y="86.36"/>
<label x="10.922" y="87.884" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-J1" gate="G$1" pin="6"/>
<wire x1="83.82" y1="147.32" x2="88.9" y2="147.32" width="0.1524" layer="91"/>
<junction x="83.82" y="147.32"/>
<label x="66.294" y="146.304" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-IC" gate="G$1" pin="VCC"/>
<wire x1="71.12" y1="109.22" x2="76.2" y2="109.22" width="0.1524" layer="91"/>
<junction x="76.2" y="109.22"/>
<label x="78.74" y="108.458" size="1.778" layer="95"/>
</segment>
</net>
<net name="ADS1110-VIN+" class="0">
<segment>
<pinref part="ADS1110-R-VD1" gate="G$1" pin="2"/>
<pinref part="ADS1110-R-VD2" gate="G$1" pin="1"/>
<wire x1="160.02" y1="149.86" x2="160.02" y2="144.78" width="0.1524" layer="91"/>
<wire x1="160.02" y1="139.7" x2="160.02" y2="144.78" width="0.1524" layer="91"/>
<wire x1="160.02" y1="144.78" x2="177.8" y2="144.78" width="0.1524" layer="91"/>
<junction x="160.02" y="144.78"/>
<pinref part="ADS1110-D-VD" gate="G$1" pin="C"/>
<wire x1="177.8" y1="144.78" x2="185.42" y2="144.78" width="0.1524" layer="91"/>
<wire x1="177.8" y1="137.16" x2="177.8" y2="144.78" width="0.1524" layer="91"/>
<junction x="177.8" y="144.78"/>
<junction x="185.42" y="144.78"/>
<label x="187.198" y="143.764" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="45.72" y1="114.3" x2="40.64" y2="114.3" width="0.1524" layer="91"/>
<pinref part="ADS1110-IC" gate="G$1" pin="VIN+"/>
<junction x="40.64" y="114.3"/>
<label x="22.098" y="113.284" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="ADS1110-J1" gate="G$1" pin="3"/>
<wire x1="33.02" y1="137.16" x2="27.94" y2="137.16" width="0.1524" layer="91"/>
<junction x="33.02" y="137.16"/>
<label x="34.544" y="136.398" size="1.778" layer="95"/>
</segment>
</net>
<net name="ADS1110-VIN-12V" class="0">
<segment>
<pinref part="ADS1110-R-VD1" gate="G$1" pin="1"/>
<wire x1="160.02" y1="160.02" x2="160.02" y2="165.1" width="0.1524" layer="91"/>
<junction x="160.02" y="165.1"/>
<label x="151.13" y="167.386" size="1.778" layer="95"/>
</segment>
<segment>
<junction x="83.82" y="137.16"/>
<pinref part="ADS1110-J1" gate="G$1" pin="4"/>
<wire x1="83.82" y1="137.16" x2="88.9" y2="137.16" width="0.1524" layer="91"/>
<label x="61.722" y="136.144" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
<errors>
<approved hash="104,1,71.12,109.22,ADS1110-IC,VCC,ADS1110-VCC,,,"/>
<approved hash="104,1,45.72,109.22,ADS1110-IC,GND,ADS1110-GND,,,"/>
</errors>
</schematic>
</drawing>
</eagle>

<?xml version='1.0' encoding='ISO-8859-1'?>
<helpset>

  <title></title>

  <maps>
    <mapref location="map.xml"/>
  </maps>

  <links>
  </links>

  <view>
    <type>oracle.help.navigator.tocNavigator.TOCNavigator</type>
    <data engine="oracle.help.engine.XMLTOCEngine">toc.xml</data>
  </view>

  <view>

  <title></title>
    <type>oracle.help.navigator.keywordNavigator.KeywordNavigator</type>
    <data engine="oracle.help.engine.XMLIndexEngine">index.xml</data>
  </view>

</helpset>

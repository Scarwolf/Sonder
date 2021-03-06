; =================================================================================================
; WeatherComJSONPollen.inc by JSMorley
; "Weather.com - Parsing the JSON" (https://forum.rainmeter.net/viewtopic.php?f=118&t=34628)
;
; Requires that WeatherComJSONVariables.inc be @Included in the skin before this file.
;
; Updated August 4, 2020
; ==================================================================================================

[@PollenSuperParent]
Measure=WebParser
URL=https://api.weather.com/v2/indices/pollen/daypart/15day?geocode=#Latitude#,#Longitude#&language=#Language#&format=json&apiKey=#APIKey#
UpdateRate=#UpdateRate#
Flags=Resync | NoCookies
UserAgent=#UserAgent#
LogSubstringErrors=0
StringIndex=1
RegExp=(?siU)^(.*)$
FinishAction=[!EnableMeasureGroup Parents]

; ====================================================
; Create Parent measures for the various data elements
; ====================================================

[@PollenValidDateStampsParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"fcstValidLocal":\[(.*),
FinishAction=[!EnableMeasureGroup Times]

[@PollenDayPartIndicatorParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"dayInd":\[(.*),
FinishAction=[!EnableMeasureGroup Times]

[@PollenDayPartNameParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"daypartName":\[(.*),

[@PollenGrassIndexParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"grassPollenIndex":\[(.*),

[@PollenGrassCategoryParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"grassPollenCategory":\[(.*),

[@PollenTreeIndexParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"treePollenIndex":\[(.*),

[@PollenTreeCategoryParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"treePollenCategory":\[(.*),
[@PollenRagweedIndexParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"ragweedPollenIndex":\[(.*),

[@PollenRagweedCategoryParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"ragweedPollenCategory":\[(.*),

; ====================================================
; Current
; ====================================================

[@PollenCurrentValidDateStamp]
Measure=WebParser
URL=[@PollenValidDateStampsParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenCurrentValidWeekDay]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@PollenCurrentValidDateStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
FormatLocale=#Language#
Format=%A

[@PollenCurrentDayPartIndicator]
Measure=WebParser
URL=[@PollenDayPartIndicatorParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenCurrentDayPartName]
Measure=WebParser
URL=[@PollenDayPartNameParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenCurrentGrassIndex]
Measure=WebParser
URL=[@PollenGrassIndexParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenCurrentGrassCategory]
Measure=WebParser
URL=[@PollenGrassCategoryParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenCurrentTreeIndex]
Measure=WebParser
URL=[@PollenTreeIndexParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenCurrentTreeCategory]
Measure=WebParser
URL=[@PollenTreeCategoryParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenCurrentRagweedIndex]
Measure=WebParser
URL=[@PollenRagweedIndexParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenCurrentRagweedCategory]
Measure=WebParser
URL=[@PollenRagweedCategoryParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[StyleSidebarBackground]
ImageName=#@#Images\SkinBackground.White.png
ScaleMargins=12,12,12,12
ImageAlpha=#GlobalSkinBackgroundAlphaInactive#
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha #GlobalSkinBackgroundAlpha#][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha #GlobalSkinBackgroundAlphaInactive#][!UpdateMeter #CURRENTSECTION#][!Redraw]
X=(#scale#*8)
Y=(#scale#*(#Month_YAdj_All#+80))
W=(#scale#*285)
H=(#scale#*200)
imagetint=#GlobalSkinBackgroundColorTint#
;DynamicVariables=1

[Background]
Meter=IMAGE
MeterStyle=StyleSidebarBackground | StyleSystemEnigmaSidebarBackground

;[StyleSidebarBackground]


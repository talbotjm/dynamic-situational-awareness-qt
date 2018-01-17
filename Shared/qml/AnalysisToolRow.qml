// Copyright 2016 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import Esri.DSA 1.0
import Esri.Vehicle 1.0
import Esri.ArcGISRuntime.Toolkit.Controls.CppApi 100.2

Row {
    id: analysisToolRow
    spacing: 10 * scaleFactor
    visible: categoryToolbar.state === "analysis"
    onVisibleChanged: state = "clear"

    states: [
        State {
            name: viewshedIcon.toolName
            PropertyChanges {
                target: viewshedIcon
                selected: true
            }
        },
        State {
            name: "clear"
            PropertyChanges {
                target: viewshedIcon
                selected: false
            }
        }
    ]

    // Viewshed Tool
    ToolIcon {
        id: viewshedIcon
        iconSource: "qrc:/Resources/icons/xhdpi/ic_menu_video_dark_d.png"
        toolName: "Viewshed"
        onToolSelected: {
            if (analysisToolRow.state === toolName)
                analysisToolRow.state = "clear";
            else {
                analysisToolRow.state = toolName;
                if (drawer.visible)
                    drawer.close();
                else {
                    toolRect.state = "analysis";
                    drawer.open();
                }
            }
        }
    }
}

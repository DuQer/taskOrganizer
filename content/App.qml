// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick
import QtQuick.Controls.Basic
import QtQml.Models
import taskOrganizer
import TaskModel 1.0

Window {
    visible: true
    width: 700
    height: 450
    title: qsTr("Task manager")
    color: "#26648E"

    // prawy panel wyświetlający listę obiektów typu Task
    RightPanel {}
}


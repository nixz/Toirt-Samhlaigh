/*
 * ScalarWidgetChangedCallbackData.cpp - Methods for ScalarWidgetChangedCallbackData class.
 *
 * Author: Patrick O'Leary
 * Created: January 19, 2008
 * Copyright 2008. All rights reserved.
 */
#include <GUI/ScalarWidget.h>
#include <GUI/ScalarWidgetChangedCallbackData.h>


/*
 * ScalarWidgetChangedCallbackData - Constructor for ScalarWidgetChangedCallbackData.
 */
ScalarWidgetChangedCallbackData::ScalarWidgetChangedCallbackData(void) {
} // end ScalarWidgetChangedCallbackData()

/*
 * ScalarWidgetChangedCallbackData - Constructor for ScalarWidgetChangedCallbackData.
 *
 * parameter _scalarWidget - ScalarWidget*
 */
ScalarWidgetChangedCallbackData::ScalarWidgetChangedCallbackData(ScalarWidget* _scalarWidget) :
	ScalarWidgetCallbackData(_scalarWidget) {
} // end ScalarWidgetChangedCallbackData()

/*
 * ~ScalarWidgetChangedCallbackData - Destructor for ScalarWidgetChangedCallbackData.
 */
ScalarWidgetChangedCallbackData::~ScalarWidgetChangedCallbackData(void) {
} // end ~ScalarWidgetChangedCallbackData()

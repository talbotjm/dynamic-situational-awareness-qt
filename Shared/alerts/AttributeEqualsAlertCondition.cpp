// Copyright 2017 ESRI
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

#include "AttributeEqualsAlertCondition.h"
#include "AttributeEqualsAlertConditionData.h"

using namespace Esri::ArcGISRuntime;

/*!
  \class AttributeEqualsAlertCondition
  \inherits AlertCondition
  \brief Represents an attribute condition which will be coninuosly monitored and will
  trigger an alert when a source object's attribute matches the target value.

  This condition will create new \l AttributeEqualsAlertConditionData to track source and target objects.
  */

/*!
  \brief Constructor taking an \l AlertLevel (\a level) the \a name of the condition and
  an optional \a parent.
 */
AttributeEqualsAlertCondition::AttributeEqualsAlertCondition(AlertLevel level,
                                                             const QString& name,
                                                             const QString& attributeName,
                                                             QObject* parent):
  AlertCondition(level, name, parent),
  m_attributeName(attributeName)
{

}

/*!
  \brief Destructor.
 */
AttributeEqualsAlertCondition::~AttributeEqualsAlertCondition()
{

}

/*!
  \brief Creates a new \l AttributeEqualsAlertConditionData to track source and target objects.
 */
AlertConditionData* AttributeEqualsAlertCondition::createData(AlertSource* source, AlertTarget* target)
{
  return new AttributeEqualsAlertConditionData(newConditionDataName(), level(), source, target, m_attributeName, this);
}

/*!
  \brief Returns the query string component for this condition in the form "[MyAttribute] =".
 */
QString AttributeEqualsAlertCondition::queryString() const
{
  return QString("[%1] = ").arg(m_attributeName);
}

/*!
  \brief Static method to extract the attribute name from a \a queryString.
 */
QString AttributeEqualsAlertCondition::attributeNameFromQueryString(const QString& queryString)
{
  if (!queryString.startsWith('['))
    return QString();

  const int endBracketIndex = queryString.indexOf(']');
  if (endBracketIndex < 2)
    return QString();

  return queryString.mid(1, endBracketIndex -1);
}

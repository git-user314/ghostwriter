﻿/***********************************************************************
 *
 * Copyright (C) 2020-2022 wereturtle
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ***********************************************************************/

#ifndef STYLESHEETBUILDER_H
#define STYLESHEETBUILDER_H

#include <QFont>
#include <QString>

#include "3rdparty/QtAwesome/QtAwesome.h"
#include "colorscheme.h"

namespace ghostwriter
{
/**
 * A convenience class to generate stylesheets for the application
 * based on the provided color scheme.
 * 
 * Variables used in CSS and QSS
 * =============================
 *
 * Use the following variables within CSS and QSS style sheets to
 * utilize the user's color scheme and interface settings:
 * 
 * $accent-color
 *      accent color, taken from theme's link color
 * $accent-fill-color
 *      accented widget background color
 *
 * $background-color
 *      application/window background color
 *
 * $secondary-background-color
 *      secondary background color for widgets above the application/window
 *      background (i.e., popup menus)
 *
 * $text-color
 *      input text field/text area/text editor text color
 * $placeholder-text-color
 *      placeholder text color for text input fields
 * $selected-text-fg-color
 *      selected text foreground color
 * $selected-text-bg-color
 *      selected text background color
 *
 * $label-color
 *      text color for labels
 * $secondary-label-color
 *      text color for labels displaying less important information
 *
 * $fill-color
 *      widget background color (i.e., buttons, input text fields, etc.)
 * $secondary-fill-color
 *      subtle background color for less important widgets
 *      (i.e., for scrollbar handles or sliders)
 * $tertiary-fill-color
 *      even more subtle background color for de-emphasized widgets
 *      (i.e., for scrollbar track)
 *
 * $separator-color
 *      border/divider/separator color to highlight important elements
 *
 * $secondary-separator-color
 *      subtle UI border/divider/separator color
 *
 * $link-color
 *      URL link color
 *
 * $error-color
 *      text color for displaying errors to the user
 * $error-fill-color
 *      widget background color for displaying errors to the user
 *
 * $warning-color
 *      text color for displaying warnings to the user
 * $warning-fill-color
 *      widget background color for displaying warnings to the user
 *
 * $info-color
 *      text color for displaying important information to the user
 * $info-fill-color
 *      widget background color for displaying information to the user
 *
 * $success-color
 *      text color for displaying success status to the user
 * $success-fill-color
 *      widget background color for displaying success status to the user
 *
 * $default-border-radius
 *      default widget border radius in pixels for rounded interface;
 *      zero for square interface
 * $scrollbar-border-radius
 *      scrollbar radius in pixels for rounded interface;
 *      zero for square interface
 *
 * $heading-color
 *      text heading color used in HTML preview
 * $code-color
 *      code color used in HTML preview
 * $code-background-color
 *      code background color used in HTML preview
 * $block-quote-color
 *      block quote color used in HTML preview
 * $grid-color
 *      table grid color used in HTML preview
 * $body-font-family
 *      HTML preview text body font family
 * $code-font-family
 *      HTML preview code font family
 * $body-font-size
 *      HTML preview text body font point size
 * $code-font-size
 *      HTML preview code font point size
 *
 * Color States
 * ============
 *
 * The following widget states are supported for any color.  Simply append the
 * color variable name with a hyphen and the state listed below to have a new
 * opacity applied.
 *
 * For example: $fill-color-hover for the hover state
 *
 * States are as follows:
 *
 * active
 * hover
 * pressed
 * disabled
 *
 */
class StyleSheetBuilder
{
public:
    /**
     * Constructor.
     */
    StyleSheetBuilder(const ColorScheme &colors,
        const bool roundedCorners,
        const QFont& previewTextFont,
        const QFont& previewCodeFont);

    /**
     * Destructor.
     */
    ~StyleSheetBuilder();

    /**
     * Removes temporary files created by the style sheet builder.
     * Call on application exit.
     */
    static void clearCache();

    /**
     * Gets the QSS style sheet for the Qt main window widgets.
     */
    QString widgetStyleSheet();

    /**
     * Gets the CSS style sheet for display in the HTML live preview.
     */
    QString htmlPreviewStyleSheet();

private:
    static QString m_statIndicatorArrowIconPath;

    QtAwesome *m_awesome;
    QMap<QString, QVariant> m_styleSheetVariables;

    QString stringValueOf(const QString &variableName) const;
    QString compileStyleSheet(const QString &path) const;
};
} // namespace ghostwriter

#endif // STYLESHEETBUILDER_H

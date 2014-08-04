/*
 * Copyright (c) 2009, Aconex.  All Rights Reserved.
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */
#ifndef APP_H
#define APP_H

#include <QtGui/QApplication>
#include <QtGui/QPixmapCache>
#include <QtGui/QFont>

class App : public QApplication
{
    Q_OBJECT

public:
    typedef enum {
	DebugApp = 0x1,
	DebugUi = 0x1,
	DebugProtocol = 0x2,
	DebugView = 0x4,
	DebugTimeless = 0x8,
	DebugForce = 0x10,
    } DebugOptions;

    App(int &, char **);
    virtual ~App() { }
    int getopts(const char *options);
    void startconsole(void);

    static QFont *globalFont();
    static int globalFontSize();

    static void nomem(void);
    static QPixmap cached(const QString &);

    static void timevalAdd(struct timeval *, struct timeval *);
    static int timevalCmp(struct timeval *, struct timeval *);
    static double timevalToSeconds(struct timeval);
    static void timevalFromSeconds(double, struct timeval *);
    static char *timeString(double);
    static char *timeHiResString(double);

    struct {
	int		argc;
	char		**argv;

	char		*pmnsfile;	/* local namespace file */
	int 		Lflag;		/* local context mode */
	char		*Sflag;		/* argument of -S flag */
	char		*Tflag;		/* argument of -T flag */
	char		*Aflag;		/* argument of -A flag */
	char		*Oflag;		/* argument of -O flag */
	int		zflag;		/* for -z (source zone) */
	char		*tz;		/* for -Z timezone */
	int		port;		/* pmtime port number */

	struct timeval	delta;
	struct timeval	logStartTime;
	struct timeval	logEndTime;
	struct timeval	realStartTime;
	struct timeval	realEndTime;
	struct timeval	position;

	QStringList	hosts;
	QStringList	archives;
	QString		tzLabel;
	QString		tzString;
    } my;
};

#endif	// APP_H

#pragma once
/*
 *      Copyright (C) 2005-2009 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

/*
 * for DESCRIPTION see 'PVRTimers.cpp'
 */

#include "DateTime.h"
#include "../addons/include/xbmc_pvr_types.h"

class CFileItem;
class CPVREpgInfoTag;
class CGUIDialogPVRTimerSettings;
class CPVRTimerInfoTag;

class CPVRTimers : public std::vector<CPVRTimerInfoTag>
{
private:
  CCriticalSection m_critSection;

public:
  CPVRTimers(void);
  bool Load() { return Update(); }
  void Unload();
  bool Update();
  int GetNumTimers();
  int GetTimers(CFileItemList* results);
  CPVRTimerInfoTag *GetTimer(CPVRTimerInfoTag *Timer);
  CPVRTimerInfoTag *GetMatch(CDateTime t);
  CPVRTimerInfoTag *GetMatch(time_t t);
  CPVRTimerInfoTag *GetMatch(const CPVREpgInfoTag *Epg, int *Match = NULL);
  CPVRTimerInfoTag *GetNextActiveTimer(void);
  bool GetDirectory(const CStdString& strPath, CFileItemList &items);
  static bool AddTimer(const CFileItem &item);
  static bool DeleteTimer(const CFileItem &item, bool force = false);
  static bool RenameTimer(CFileItem &item, CStdString &newname);
  static bool UpdateTimer(const CFileItem &item);
  bool Update(const CPVRTimerInfoTag &timer);
  void Clear();
};

extern CPVRTimers PVRTimers;
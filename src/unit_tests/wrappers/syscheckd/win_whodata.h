/*
 * Copyright (C) 2015-2020, Wazuh Inc.
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 2) as published by the FSF - Free Software
 * Foundation.
 */
#ifndef UNIT_TEST_WRAPPERS_WIN_WHODATA
#define UNIT_TEST_WRAPPERS_WIN_WHODATA

#ifdef WIN32
#include <windows.h>
#include <accctrl.h>

BOOL WINAPI wrap_win_whodata_OpenProcessToken(
  HANDLE  ProcessHandle,
  DWORD   DesiredAccess,
  PHANDLE TokenHandle
);

DWORD WINAPI wrap_win_whodata_GetLastError();

BOOL WINAPI wrap_win_whodata_LookupPrivilegeValue(
  LPCSTR lpSystemName,
  LPCSTR lpName,
  PLUID  lpLuid
);

WINBOOL WINAPI wrap_win_whodata_CloseHandle(HANDLE hObject);

WINBOOL WINAPI wrap_win_whodata_AdjustTokenPrivileges(
  HANDLE TokenHandle,
  WINBOOL DisableAllPrivileges,
  __attribute__ ((unused)) PTOKEN_PRIVILEGES NewState,
  __attribute__ ((unused)) DWORD BufferLength,
  __attribute__ ((unused)) PTOKEN_PRIVILEGES PreviousState,
  __attribute__ ((unused)) PDWORD ReturnLength
);

DWORD WINAPI wrap_win_whodata_GetNamedSecurityInfo(
  LPCSTR               pObjectName,
  SE_OBJECT_TYPE       ObjectType,
  SECURITY_INFORMATION SecurityInfo,
  PSID                 *ppsidOwner,
  PSID                 *ppsidGroup,
  PACL                 *ppDacl,
  PACL                 *ppSacl,
  PSECURITY_DESCRIPTOR *ppSecurityDescriptor
);

#endif
#endif
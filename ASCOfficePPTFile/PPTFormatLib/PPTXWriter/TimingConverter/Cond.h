/*
 * (c) Copyright Ascensio System SIA 2010-2019
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at 20A-12 Ernesta Birznieka-Upisha
 * street, Riga, Latvia, EU, LV-1050.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */
#pragma once

#include "../../../ASCOfficePPTXFile/PPTXFormat/Logic/Timing/Seq.h"
#include "../../Records/Animations/ExtTimeNodeContainer.h"

namespace PPT_FORMAT
{
void FillCond(PPT_FORMAT::CRecordTimeConditionContainer *oldCond, PPTX::Logic::Cond &cond)
{
    if (oldCond->m_oTimeConditionAtom.m_nTimeDelay != -1)
        cond.delay = std::to_wstring(oldCond->m_oTimeConditionAtom.m_nTimeDelay);
    else
        cond.delay = L"indefinite";

    if (oldCond->m_oTimeConditionAtom.m_TriggerObject == TL_TOT_RuntimeNodeRef)
    {
        cond.tn = oldCond->m_oTimeConditionAtom.m_nID;
    }

    std::wstring str;

    switch (oldCond->m_oTimeConditionAtom.m_nTriggerEvent)
    {
    case 1:     str =   L"onBegin"; break;
    case 3:     str =   L"begin"; break;
    case 4:     str =   L"end"; break;
    case 5:     str =   L"onClick"; break;
    case 7:     str =   L"onMouseOver"; break;
    case 9:     str =   L"onNext"; break;
    case 10:    str =   L"onPrev"; break;
    case 11:    str =   L"onStopAudio"; break;
    default:    str.clear();
    }

    if (!str.empty()) cond.evt = str;

    // TODO
//    if (oldCond->m_oVisualElement.)
//    cond.tgtEl = new PPTX::Logic::TgtEl();
}
}


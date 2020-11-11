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

#include "CString.h"
#include "Text/StyleTextProp9Atom.h"
#include "Text/StyleTextProp10Atom.h"
#include "Text/StyleTextProp11Atom.h"

#define TN_PPT9 L"___PPT9"
#define TN_PPT10 L"___PPT10"
#define TN_PPT11 L"___PPT11"

namespace PPT_FORMAT
{
class CRecordPP9ShapeBinaryTagExtension : public CUnknownRecord
{
public:
    CRecordStyleTextProp9Atom m_styleTextPropAtom;


    void ReadFromStream(SRecordHeader &oHeader, POLE::Stream *pStream) override
    {
        m_oHeader = oHeader;

        SRecordHeader ReadHeader;
        ReadHeader.ReadFromStream(pStream);

        m_styleTextPropAtom.ReadFromStream(ReadHeader, pStream);
    }
};

class CRecordPP10ShapeBinaryTagExtension : public CUnknownRecord
{
public:
    CRecordStyleTextProp10Atom m_styleTextPropAtom;


    void ReadFromStream(SRecordHeader &oHeader, POLE::Stream *pStream) override
    {
        m_oHeader = oHeader;

        SRecordHeader ReadHeader;
        ReadHeader.ReadFromStream(pStream);

        m_styleTextPropAtom.ReadFromStream(ReadHeader, pStream);
    }
};

class CRecordPP11ShapeBinaryTagExtension : public CUnknownRecord
{
public:
    CRecordStyleTextProp11Atom m_styleTextPropAtom;


    void ReadFromStream(SRecordHeader &oHeader, POLE::Stream *pStream) override
    {
        m_oHeader = oHeader;

        SRecordHeader ReadHeader;
        ReadHeader.ReadFromStream(pStream);

        m_styleTextPropAtom.ReadFromStream(ReadHeader, pStream);
    }
};

class CRecordShapeProgBinaryTagSubContainerOrAtom : public CUnknownRecord
{
public:
    nullable<IRecord>           m_pTagContainer;
    nullable<CRecordCString>    m_pTagName;

    void ReadFromStream(SRecordHeader &oHeader, POLE::Stream *pStream) override
    {
        m_oHeader = oHeader;
        LONG lPos = 0; StreamUtils::StreamPosition(lPos, pStream);

        SRecordHeader ReadHeader;
        ReadHeader.ReadFromStream(pStream);

        if (m_oHeader.RecType == RT_CString)
        {
            m_pTagName = new CRecordCString();
            m_pTagName->ReadFromStream(ReadHeader, pStream);

            SRecordHeader childHeader;
            if (!childHeader.ReadFromStream(pStream))
                return;

            if (m_pTagName->m_strText == TN_PPT9) {
                m_pTagContainer = new CRecordPP9ShapeBinaryTagExtension();
                dynamic_cast<CRecordPP9ShapeBinaryTagExtension*>
                        (m_pTagContainer.GetPointer())->ReadFromStream(childHeader, pStream);
            } else if (m_pTagName->m_strText == TN_PPT10) {
                m_pTagContainer = new CRecordPP10ShapeBinaryTagExtension();
                dynamic_cast<CRecordPP10ShapeBinaryTagExtension*>
                        (m_pTagContainer.GetPointer())->ReadFromStream(childHeader, pStream);
            } else if (m_pTagName->m_strText == TN_PPT11) {
                m_pTagContainer = new CRecordPP11ShapeBinaryTagExtension();
                dynamic_cast<CRecordPP11ShapeBinaryTagExtension*>
                        (m_pTagContainer.GetPointer())->ReadFromStream(childHeader, pStream);
            }
        }
    }
};
}

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


#include "../Reader/Records.h"
#include "../Enums/_includer.h"


namespace PPT_FORMAT
{

class CRecordTimeVariant : public CUnknownRecord
{
public:
    virtual void ReadFromStream ( SRecordHeader & oHeader, POLE::Stream* pStream )
    {
        m_oHeader			=	oHeader;

        m_Type				=	( TimeVariantTypeEnum )StreamUtils::ReadBYTE ( pStream );	//

        LONG lPos		=	0;
        StreamUtils::StreamPosition ( lPos, pStream );

        StreamUtils::StreamSeek ( lPos + m_oHeader.RecLen, pStream );
    }

public:
    TimeVariantTypeEnum		m_Type;
};


class CRecordTimeVariantBool : public CRecordTimeVariant
{
public:
    virtual void ReadFromStream ( SRecordHeader & oHeader, POLE::Stream* pStream )
    {
        m_oHeader			=	oHeader;

        m_Type				=	( TimeVariantTypeEnum )StreamUtils::ReadBYTE ( pStream );	//	MUST be TL_TVT_Bool
        m_Value				=	( 0x1 == StreamUtils::ReadBYTE ( pStream ) );
    }

public:
    TimeVariantTypeEnum		m_Type;
    bool					m_Value;
};

class CRecordTimeVariantInt : public CRecordTimeVariant
{
public:
    virtual void ReadFromStream ( SRecordHeader & oHeader, POLE::Stream* pStream )
    {
        m_oHeader			=	oHeader;

        m_Type				=	( TimeVariantTypeEnum )StreamUtils::ReadBYTE ( pStream );	//	MUST be TL_TVT_Bool
        m_Value				=	StreamUtils::ReadDWORD ( pStream );
    }

public:

    TimeVariantTypeEnum		m_Type;
    _UINT32                         m_Value;
};

class CRecordTimeVariantFloat : public CRecordTimeVariant
{
public:
    virtual void ReadFromStream ( SRecordHeader & oHeader, POLE::Stream* pStream )
    {
        m_oHeader			=	oHeader;

        m_Type				=	( TimeVariantTypeEnum )StreamUtils::ReadBYTE ( pStream );	//	MUST be TL_TVT_Bool
        m_Value				=	StreamUtils::ReadFLOAT ( pStream );
    }

public:

    TimeVariantTypeEnum		m_Type;
    FLOAT                           m_Value;
};

class CRecordTimeVariantString : public CRecordTimeVariant
{
public:
    virtual void ReadFromStream ( SRecordHeader & oHeader, POLE::Stream* pStream )
    {
        m_oHeader			=	oHeader;

        m_Type				=	( TimeVariantTypeEnum )StreamUtils::ReadBYTE ( pStream );	//	MUST be TL_TVT_String

        if ( WCHAR* pString = new WCHAR [ m_oHeader.RecLen / 2 ] )
        {
            POLE::uint64 res = pStream->read ((unsigned char*) pString, ( m_oHeader.RecLen / 2 ) * 2) ;

            if (res > 0)
            {
                if (sizeof(wchar_t) == 4)
                {
                    //todoooo
                }
                else
                    m_stringValue		=	std::wstring ( pString );
            }

            RELEASEARRAYOBJECTS ( pString );
        }
    }

public:

    TimeVariantTypeEnum		m_Type;
    std::wstring                    m_stringValue;
};



class CRecordTimeDisplayType : public CRecordTimeVariantInt
{

};

class CRecordTimeMasterRelType : public CRecordTimeVariantInt
{

};

class CRecordTimeSubType : public CRecordTimeVariantInt
{

};

class CRecordTimeEffectID : public CRecordTimeVariantInt
{

};

class CRecordTimeEffectDir  : public CRecordTimeVariantInt
{

};

class CRecordTimeEffectType : public CRecordTimeVariantInt
{

};

class CRecordTimeAfterEffect : public CRecordTimeVariantBool
{

};

class CRecordTimeSlideCount : public CRecordTimeVariantInt
{

};

class CRecordTimeNodeTimeFilter : public CRecordTimeVariantString
{

};

class CRecordTimeEventFilter : public CRecordTimeVariantString
{

};

class CRecordTimeHideWhenStopped : public CRecordTimeVariantBool
{

};

class CRecordTimeGroupID : public CRecordTimeVariantInt
{

};

class CRecordTimeEffectNodeType  : public CRecordTimeVariantInt
{

};

class CRecordTimePlaceholderNode : public CRecordTimeVariantBool
{

};

class CRecordTimeMediaVolume : public CRecordTimeVariantFloat
{

};

class CRecordTimeMediaMute : public CRecordTimeVariantBool
{

};

class CRecordTimeZoomToFullScreen : public CRecordTimeVariantBool
{

};


class CRecordTimeRuntimeContext : public CRecordTimeVariantString
{

};

class CRecordColorModel : public CRecordTimeVariantInt
{

};

class CRecordTimeColorModel: public CRecordTimeVariantInt
{

};

class CRecordTimeColorDirection : public CRecordTimeVariantInt
{

};

class CRecordTimeOverride : public CRecordTimeVariantInt
{

};

class CRecordTimePointsTypes : public CRecordTimeVariantString
{

};
}
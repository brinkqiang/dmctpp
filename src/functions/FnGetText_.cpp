/*-
 * Copyright (c) 2004 - 2011 CTPP Team
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the CTPP Team nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *      FnGetText_.cpp
 *
 * $CTPP$
 */

#include "CDT.hpp"
#include "CTPP2Logger.hpp"
#include "FnGetText_.hpp"

#include <strings.h>
#include "CTPP2GetText.hpp"

namespace CTPP // C++ Template Engine
{

//
// Constructor
//
FnGetText_::FnGetText_() : pGetText(NULL)
{
	;;
}

//
// Handler
//
INT_32 FnGetText_::Handler(CDT            * aArguments,
                           const UINT_32    iArgNum,
                           CDT            & oCDTRetVal,
                           Logger         & oLogger)
{
	if (pGetText == NULL)
	{
		oLogger.Emerg("GetText object is NULL");
		return -1;
	}

	if (iArgNum == 1)
	{
		oCDTRetVal = pGetText -> FindMessage(sLanguage, aArguments[0].GetString());
		return 0;
	}
	else if (iArgNum == 2)
	{
		oCDTRetVal = pGetText -> FindMessage(sLanguage, aArguments[1].GetString(), aArguments[0].GetString());
		return 0;
	}
	else if (iArgNum == 3)
	{
		oCDTRetVal = pGetText -> FindPluralMessage(sLanguage, aArguments[2].GetString(),
		                                     aArguments[1].GetString(), aArguments[0].GetUInt());
		return 0;
	}
	else if (iArgNum == 4)
	{
		oCDTRetVal = pGetText -> FindPluralMessage(sLanguage, aArguments[3].GetString(), aArguments[2].GetString(),
		                                     aArguments[1].GetUInt(), aArguments[0].GetString());
		return 0;
	}

	oLogger.Emerg("Usage: _(message) or _(message, domain) or _(message, plural_message, count) or _(message, plural_message, count, domain)");
return -1;
}

//
// Get function name
//
CCHAR_P FnGetText_::GetName() const { return "_"; }

//
// A destructor
//
FnGetText_::~FnGetText_() throw() { ;; }

//
// Set GetText object
//
void FnGetText_::SetGetText(CTPP2GetText * pGetText_) { pGetText = pGetText_; }

//
// Set language of translation
//
void FnGetText_::SetLanguage(const STLW::string & sLang) { sLanguage = sLang; }

} // namespace CTPP
// End.

/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2011 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#include "LuceneInc.h"
#include "WhitespaceAnalyzer.h"
#include "WhitespaceTokenizer.h"

namespace Lucene
{
    WhitespaceAnalyzer::~WhitespaceAnalyzer()
    {
    }

    TokenStreamPtr WhitespaceAnalyzer::tokenStream(const String& fieldName, ReaderPtr reader)
    {
        return newLucene<WhitespaceTokenizer>(reader);
    }

    TokenStreamPtr WhitespaceAnalyzer::reusableTokenStream(const String& fieldName, ReaderPtr reader)
    {
        TokenizerPtr tokenizer(gc_ptr_dynamic_cast<Tokenizer>(getPreviousTokenStream()));
        if (!tokenizer)
        {
            tokenizer = newLucene<WhitespaceTokenizer>(reader);
            setPreviousTokenStream(tokenizer);
        }
        else
            tokenizer->reset(reader);
        return tokenizer;
    }
}

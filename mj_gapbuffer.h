#pragma once

namespace mj
{
  // Operates on UTF-8.
  struct GapBuffer
  {
    char* pBufBegin;
    char* pBufEnd;
    char* pGapBegin;
    char* pGapEnd;
    char* pCursor;
  };

  unsigned int GapBufferGetVirtualCursorPosition(const GapBuffer* pBuf);
  void GapBufferJumpEndOfLine(GapBuffer* pBuf);
  void GapBufferJumpStartOfLine(GapBuffer* pBuf);
  void GapBufferInsertCharacterAtCursor(GapBuffer* pBuf, wchar_t c);
  void GapBufferIncrementCursor(GapBuffer* pBuf);
  void GapBufferDecrementCursor(GapBuffer* pBuf);
  void GapBufferDeleteAtCursor(GapBuffer* pBuf);
  void GapBufferBackspaceAtCursor(GapBuffer* pBuf);
  void GapBufferInit(GapBuffer* pBuf, void* pBegin, void* pEnd);
  void GapBufferSetText(GapBuffer* pBuf, const wchar_t* pText);
} // namespace mj
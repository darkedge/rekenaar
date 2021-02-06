#include "VerticalLayout.h"
#include "HorizontalResizeControl.h"

void mj::VerticalLayout::Paint(ID2D1RenderTarget* pRenderTarget)
{
  static_cast<void>(pRenderTarget);

  for (size_t i = 0; i < this->controls.Size(); i++)
  {
    Control* pControl = this->controls[i];
    pControl->OnPaint(pRenderTarget);
  }
}

void mj::VerticalLayout::MoveResizeControl(Control* pFirst, Control* pResizeControl, Control* pSecond, int16_t dx,
                                           int16_t dy)
{
  static_cast<void>(dx);

  pFirst->height += dy;
  pResizeControl->yParent += dy;
  pSecond->yParent += dy;
  pSecond->height -= dy;
}

void mj::VerticalLayout::OnSize()
{
  const int16_t numControls = static_cast<int16_t>(this->controls.Size());

  if (numControls > 0)
  {
    int16_t numResizeControls         = numControls / 2;
    int16_t numPanels                 = numResizeControls + 1;
    int16_t totalResizeControlsHeight = numResizeControls * HorizontalResizeControl::HEIGHT;

    // TODO: This integer division can leave blank columns if there is a remainder
    int16_t panelHeight = (this->height - totalResizeControlsHeight) / numPanels;
    int16_t y           = 0;

    for (size_t i = 0; i < numControls; i++)
    {
      Control* pControl = this->controls[i];

      pControl->xParent = 0;
      pControl->yParent = y;
      if (!(i & 1))
      {
        pControl->height = panelHeight;
      }
      pControl->width = this->width;
      pControl->OnSize();

      y += pControl->height;
    }
  }
}

void mj::VerticalLayout::Add(mj::Control* pControl)
{
  if (this->controls.Size() > 0)
  {
    Control* pResizeControl = this->pAllocator->New<HorizontalResizeControl>();
    pResizeControl->Init(this->pAllocator);
    this->controls.Add(pResizeControl);
  }
  this->controls.Add(pControl);
}

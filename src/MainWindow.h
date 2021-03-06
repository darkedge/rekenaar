#pragma once
#include "ResourcesWin32.h"
#include "DirectoryNavigationPanel.h"

struct IDCompositionDesktopDevice;
struct IDCompositionVirtualSurface;
struct IDCompositionTarget;
struct ID2D1RenderTarget;

namespace mj
{
  class MainWindow
  {
  private:
    static constexpr const size_t WIDTH  = 3;
    static constexpr const size_t HEIGHT = 2;
    DirectoryNavigationPanel panel;
    IDCompositionDesktopDevice* dcompDevice = nullptr;
    IDCompositionVirtualSurface* pSurface   = nullptr;
    IDCompositionTarget* pTarget            = nullptr;
    MARGINS margins                         = {};

    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    void Resize();
    void OnPaint();
    void Destroy();

  public:
    void Run();
    void OnCreateID2D1RenderTarget(IDCompositionDesktopDevice* dcompDevice, ID2D1RenderTarget* pRenderTarget);
    void ExtendFrame(HWND hwnd);
    LRESULT DetermineNonClientWindowArea(HWND hWnd, WPARAM, LPARAM lParam, LONG captionHeight);
  };

} // namespace mj

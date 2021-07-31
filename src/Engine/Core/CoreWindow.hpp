#include "CoreRender.hpp"

#ifndef __COREWINDOW_H__
#define __COREWINDOW_H__

namespace UnderScore::Engine::Core
{
    struct CoreWindow 
    {
        public:
            virtual void SetCoreRender(CoreRender& render) = 0;
            virtual void Init(void) = 0;
            virtual void Render(void) = 0;
            virtual void Update(double detla) = 0;
            virtual void Dispose(void) = 0;
    };
}

#endif // __COREWINDOW_H__
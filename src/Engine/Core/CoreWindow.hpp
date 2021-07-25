#ifndef __COREWINDOW_H__
#define __COREWINDOW_H__

namespace UnderScore::Engine::Core 
{
    class CoreWindow 
    {
        public:
            virtual void Init(void);
            virtual void Render(void);
            virtual void Update(float detla);
            virtual void Dispose(void);
    };
}


#endif // __COREWINDOW_H__
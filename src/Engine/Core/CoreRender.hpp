#ifndef __CORERENDER_H__
#define __CORERENDER_H__

namespace UnderScore::Engine::Core 
{
    class CoreRender 
    {
        public:
        virtual void Init() {};
        virtual void Render() {};
        virtual void Update(double delta) {};
    };
}

#endif // __CORERENDER_H__
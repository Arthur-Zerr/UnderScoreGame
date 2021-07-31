#include "../Core/CoreWindow.hpp"

namespace UnderScore::Engine::Window 
{
    class GLFWWindow : public UnderScore::Engine::Core::CoreWindow 
    {
        public:
        UnderScore::Engine::Core::CoreRender& render;
        void SetCoreRender(UnderScore::Engine::Core::CoreRender& render) override
        {
            this->render = render;
        }


        virtual void Init(void) override
        {
            std::cout << "Init" << std::endl;
        }

        virtual void Render(void) override
        {
            std::cout << "Renderer" << std::endl;
        }

        virtual void Update(double delta) override 
        {

        }

        virtual void Dispose(void) override {
            
        }
    };
}
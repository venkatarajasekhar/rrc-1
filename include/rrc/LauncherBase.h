/**
 *  @autor arssivka
 *  @date 7/8/16
 */

#pragma once


#include "RootNode.h"
#include "Node.h"

namespace rrc {
    class LauncherBase {
    public:
        virtual ~LauncherBase() { }

        virtual int run() = 0;

        virtual bool step() = 0;

        virtual void stop() = 0;

        virtual void setRootNode(RootNodePtr node) = 0;

        virtual void addNode(NodePtr node) = 0;

        virtual void removeNode(NodePtr node) = 0;
    };

    typedef LauncherBase Launcher;
}



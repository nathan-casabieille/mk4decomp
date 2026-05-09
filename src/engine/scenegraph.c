/**
 * Scene-graph allocator wrappers.
 */
#include "engine/scenegraph.h"

/*
 * Convenience: allocate a node using the type cached in
 * g_pendingNodeType. Lets a hot path skip re-passing the type.
 *
 * @addr 0x0049cb60
 */
void *AllocNode(void)
{
    return AllocateNode(g_pendingNodeType);
}

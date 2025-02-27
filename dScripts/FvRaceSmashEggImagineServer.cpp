#include "CharacterComponent.h"
#include "DestroyableComponent.h"
#include "EntityManager.h"
#include "FvRaceSmashEggImagineServer.h"
#include "PossessableComponent.h"
#include "RacingTaskParam.h"

void FvRaceSmashEggImagineServer::OnDie(Entity *self, Entity *killer) {
    if (killer != nullptr) {
        auto* destroyableComponent = killer->GetComponent<DestroyableComponent>();
        if (destroyableComponent != nullptr) {
            destroyableComponent->SetImagination(destroyableComponent->GetImagination() + 10);
            EntityManager::Instance()->SerializeEntity(killer);
        }

        // get possessor to progress statistics and tasks.
        auto* possessableComponent = killer->GetComponent<PossessableComponent>();
        if (possessableComponent != nullptr) {

            auto* possessor = EntityManager::Instance()->GetEntity(possessableComponent->GetPossessor());
            if (possessor != nullptr) {

                auto* missionComponent = possessor->GetComponent<MissionComponent>();
                auto* characterComponent = possessor->GetComponent<CharacterComponent>();
                if (characterComponent != nullptr) {
                    characterComponent->UpdatePlayerStatistic(ImaginationPowerUpsCollected);
                    characterComponent->UpdatePlayerStatistic(RacingSmashablesSmashed);
                }
                if (missionComponent == nullptr) return;
                missionComponent->Progress(MissionTaskType::MISSION_TASK_TYPE_RACING, self->GetLOT(), (LWOOBJID)RacingTaskParam::RACING_TASK_PARAM_SMASH_DRAGON_EGGS);
            }
        }

    }
}

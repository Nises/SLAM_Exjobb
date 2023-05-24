
"use strict";

let CleanupLocalGrids = require('./CleanupLocalGrids.js')
let GetNodesInRadius = require('./GetNodesInRadius.js')
let RemoveLabel = require('./RemoveLabel.js')
let GlobalBundleAdjustment = require('./GlobalBundleAdjustment.js')
let ResetPose = require('./ResetPose.js')
let GetPlan = require('./GetPlan.js')
let SetGoal = require('./SetGoal.js')
let DetectMoreLoopClosures = require('./DetectMoreLoopClosures.js')
let GetMap = require('./GetMap.js')
let GetNodeData = require('./GetNodeData.js')
let LoadDatabase = require('./LoadDatabase.js')
let PublishMap = require('./PublishMap.js')
let SetLabel = require('./SetLabel.js')
let ListLabels = require('./ListLabels.js')
let AddLink = require('./AddLink.js')
let GetMap2 = require('./GetMap2.js')

module.exports = {
  CleanupLocalGrids: CleanupLocalGrids,
  GetNodesInRadius: GetNodesInRadius,
  RemoveLabel: RemoveLabel,
  GlobalBundleAdjustment: GlobalBundleAdjustment,
  ResetPose: ResetPose,
  GetPlan: GetPlan,
  SetGoal: SetGoal,
  DetectMoreLoopClosures: DetectMoreLoopClosures,
  GetMap: GetMap,
  GetNodeData: GetNodeData,
  LoadDatabase: LoadDatabase,
  PublishMap: PublishMap,
  SetLabel: SetLabel,
  ListLabels: ListLabels,
  AddLink: AddLink,
  GetMap2: GetMap2,
};

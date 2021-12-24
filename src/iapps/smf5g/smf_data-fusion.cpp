    //TODO: Disable the fusion data mode for the moment

    //   // todo: field fusion depends on the event
    //   if (j.contains("event")){
    //     // UE_IP_CH
    //     std::string event = j["event"];
    //     if (event == "UE_IP_CH") {
    //       if(j.find("adIpv4Addr") != j.end())
    //       {
    //           o.setAdIpv4Addr(j.at("adIpv4Addr"));
    //       }

    //     } // FLEXCN
    //     else if (event == "FLEXCN") {
    //       if(j.find("customized_data") != j.end()){
    //         auto j_cstm_data = j.at("customized_data");

    //         Logger::flexcn_app().info("Info format : ue_ipv4_addr");
    //         Logger::flexcn_app().info(j_cstm_data.at("ue_ipv4_addr").dump(4).c_str());
            
    //         if(j_cstm_data.find("ue_ipv4_addr") != j_cstm_data.end())
    //         {
    //             try{
    //             o.setUeIpv4Addr(j_cstm_data.at("ue_ipv4_addr"));
    //           } catch (std::exception&   e){
    //               Logger::flexcn_app().error("Error format : ue_ipv4_addr");
    //               Logger::flexcn_app().error(e.what());
    //           }
    //         }
            
    //         Logger::flexcn_app().info("format : adIpv4Addr");

    //         if(j_cstm_data.find("adIpv4Addr") != j_cstm_data.end())
    //         {
    //           try{
    //             o.setAmfAddr(j_cstm_data.at("adIpv4Addr"));
    //           } catch (std::exception&   e){
    //               Logger::flexcn_app().error("Error format : adIpv4Addr");
    //               Logger::flexcn_app().error(e.what());
    //           }
    //         }

    //         Logger::flexcn_app().info("Info format : dnn");
    //         if(j_cstm_data.find("dnn") != j_cstm_data.end())
    //         {
                
    //             try{
    //             o.setDnn(j_cstm_data.at("dnn"));
    //           } catch (std::exception&   e){
    //               Logger::flexcn_app().error("Error format : dnn");
    //               Logger::flexcn_app().error(e.what());
    //           }
    //         }

    //         Logger::flexcn_app().info("Info format : pdu_session_type");
    //         if(j_cstm_data.find("pdu_session_type") != j_cstm_data.end())
    //         {
               
    //             try{
    //                 o.setPduSessionType(j_cstm_data.at("pdu_session_type"));              
    //             } catch (std::exception&   e){
    //               Logger::flexcn_app().error("Error format : pdu_session_type");
    //               Logger::flexcn_app().error(e.what());
    //           }
    //         }

    //         Logger::flexcn_app().info("Info format : plmn");
    //         if(j_cstm_data.find("plmn") != j_cstm_data.end())
    //         {
                

    //             try{
    //               PlmnId plmnid;
    //               from_json(j_cstm_data.at("plmn"), plmnid);
    //               o.setPlmnId(plmnid);              
    //             } catch (std::exception&   e){
    //               Logger::flexcn_app().error("Error format : plmn");
    //               Logger::flexcn_app().error(e.what());
    //           }
    //         }
            
    //         Logger::flexcn_app().info("Info format : qos_flow");
    //         if(j_cstm_data.find("qos_flow") != j_cstm_data.end())
    //         {
              

    //           try{
    //                 std::vector<FlowProfile> v_fp;
    //                 // TODO: verify if this is a valid array
    //                 for (auto j_flow : j_cstm_data["qos_flow"]){
    //                     // FIXME: wrong type of an_addr 
    //                     FlowProfile fp;
    //                     // from_json(j_flow, fp);
    //                     fp.setAnAddr(j_flow["an_addr"]["ipv4"]);
    //                     fp.setUpfAddr(j_flow["upf_addr"]["ipv4"]);
    //                     fp.setQfi(j_flow["qfi"]);
    //                     v_fp.push_back(fp);
    //                 }
    //                 o.setFlows(v_fp);
    //           } catch (std::exception&   e){
    //               Logger::flexcn_app().error("Error format : qos_flow");
    //               Logger::flexcn_app().error(e.what());
    //           }
    //         }
    //       }
    //     }


        
        
    //     Logger::flexcn_app().info("Info format : pduSeId");
    //     if(j.find("pduSeId") != j.end())
    //     {
            
    //         try{
    //             o.setPduSeId(j.at("pduSeId"));
    //           } catch (std::exception&   e){
    //               Logger::flexcn_app().error("Error format : pduSeId");
    //               Logger::flexcn_app().error(e.what());
    //           }
    //     }

    //     Logger::flexcn_app().info("Info format : supi");
    //     if(j.find("supi") != j.end())
    //     {
            
    //         try{
    //             o.setSupi(j.at("supi"));
    //           } catch (std::exception&   e){
    //               Logger::flexcn_app().error("Error format : supi");
    //               Logger::flexcn_app().error(e.what());
    //           }
    //     }
    //   }
    //   success = true;
    //   send_to_database(o);
    //   if (o.is_all_setted()){
    //     send_to_database(o);
    //   }


========================================

 // get UE ID from data_event
  // std::string supi = data_event.getSupi();

  // get the item from the list of app that has the same ueid
  // data structure: ueid as key,
  // m_database[supi].merge(data_event);

  // update the data related to this ue with the new data fields.
  // if event == event_0:
  //     update these field of data that related to this ueid address
  // if ueid in m_datase:
  //     current_ue_context = m_database.get(ueid)
  //     current_ue_context.update(data_event)
  // else:
  //     new_context = new ue_context()
  // how far should we update these items.
  // done the process.
//   Logger::flexcn_app().error(std::to_string(m_database.size()).c_str());